#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <limits.h>
#include <memory/vaddr.h>

enum {
  TK_NOTYPE = 256,
  TK_EQ = 255,
  TK_NUM = 128,

  TK_REG = 129,
  TK_NEG,
  TK_DER, // 解引用

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"==", TK_EQ},        // equal

  {"0[xX][0-9a-fA-F]+", TK_NUM},
  {"0[bB][0-1]+", TK_NUM},
  {"0[0-8]+", TK_NUM},
  {"[0-9]+", TK_NUM},
  // 匹配负数，-(-2) -> -2 ,--2 -> -2
  // {"(?<=[+-*/][^0-9].)-0[xX][0-9a-fA-F]+", TK_HEX},
  // {"(?<=[+-*/][^0-9].)-0[bB][0-1]+", TK_BIN},
  // {"(?<=[+-*/][^0-9].)-0[0-8]+", TK_OCT},
  // {"(?<=[+-*/][^0-9].)-[0-9]+", TK_NUM},
  // 寄存器
  {"\\$[a-z\\$][a-z0-9]+", TK_REG},
  {"-", '-'},
  // {" -", TK_NEGETIVE},
  {"\\*", '*'},
  {"/", '/'},
  {"\\(", '('},
  {"\\)", ')'},
  {"\\s", TK_NOTYPE},
  // {"0[xX][0-9]+", TK_HEX},
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32000] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //     i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_NOTYPE: break;
          default:
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';    // bug fix
            nr_token++;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

static word_t str2val(char *num, bool *success) {
  word_t x = 0;
  if (*num != '0') {
    x = strtoul(num, NULL, 10);
  }
  else {
    num ++;
    switch (*num) {
    case 'b': case 'B':
      num ++;
      x = strtoul(num, NULL, 2);
      break;
    case 'x': case 'X':
      num ++;
      x = strtoul(num, NULL, 16);
      break;
    default:
      x = strtoul(num, NULL, 8);
    }
  }
  if (x == ULONG_MAX) {
    *success = false;
    // return 0;
  }
  return x;
}

static bool check_parentheses(int p, int q, bool *success) {
  int stack = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(')
      stack++;
    else if (tokens[i].type == ')')
      stack--;
    if (stack == 0 && i != q) {
      return false;
    }
    if (stack < 0) {
      printf("'(',')'error i:%d,p:%d,q:%d \n",i,p,q);
      *success = false;
      return false;
    }
  }
  if (stack != 0) {
    *success = false;
    return false;
  }
  if (tokens[p].type == '(' && tokens[q].type == ')') {
    return true;
  }
  return false;
}

// 从右到左运算
static int find_main_op(int p, int q, bool *success) {
  int op_index = p;
  int stack = 0;
  for (int i = p; i <= q; i++) {
    switch (tokens[i].type) {
      case '(': stack++; break;
      case ')': stack--; break;
      case '+': case '-':
        if (stack == 0) {
          op_index = i;
        }
        break;
      case '*': case '/':
        if (stack == 0 && (tokens[op_index].type != '+' ||
          tokens[op_index].type != '-')) {
          op_index = i;
        }
        break;
      case TK_NEG: case TK_DER:
        if (stack == 0 && (tokens[op_index].type == TK_NEG ||
          tokens[op_index].type == TK_DER)) {
          op_index = i;
        }
        break;
      default: break;
    }
    if (stack < 0) {
      *success = false;
      return 0;
    }
  }
  return op_index;
}

static word_t eval(int p, int q, bool *success) {
  if (*success == false) { return 0; }
  if (p > q) {
    *success = false;
    return 0;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    if (tokens[p].type == TK_NUM) {
      return str2val(tokens[p].str, success);
    }
    else if (tokens[p].type == TK_REG) {
      bool s;
      word_t v = isa_reg_str2val(tokens[p].str + 1, &s);
      if (s == true) { return v; }
      return false;
    }
    *success = false;
    return 0;
  }
  else if (check_parentheses(p, q, success) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1, success);
  }
  else {
    // find the position of 主运算符 in the token expression
    int op_index = find_main_op(p, q, success);
    // printf("%d op:%c\n", op, tokens[op].type);

    // if (*success == false) { return 0; }

    switch (tokens[op_index].type) {
      case '+':
        return eval(p, op_index - 1, success) +
        eval(op_index + 1, q, success);
      case '-':
        return eval(p, op_index - 1, success) - 
        eval(op_index + 1, q, success);
      case '*':
        return eval(p, op_index - 1, success) * 
        eval(op_index + 1, q, success);
      case '/':
        return eval(p, op_index - 1, success) / 
        eval(op_index + 1, q, success);
      case TK_NEG:
        return -eval(op_index + 1, q, success);
      case TK_DER:
        return vaddr_read(eval(op_index + 1, q, success), 4);
      default:
        *success = false;
        return 0;
    }
  }
}

word_t expr(char *e, bool *success) {
  *success = true;
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  // 修正特殊类型
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '-' && (i == 0 || tokens[i - 1].type != TK_NUM)) {
      tokens[i].type = TK_NEG;
    }
    if (tokens[i].type == '*' && (i == 0 || tokens[i - 1].type != TK_NUM)) {
      tokens[i].type = TK_DER;
    }
    // printf("type:%d, str:%s\n", tokens[i].type, tokens[i].str);
  }

  return eval(0, nr_token-1, success);
}
