#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned long long result = %s; "
"  printf(\"%%llu\", result); "
"  return 0; "
"}";

static int bufp = 0;
static int count = 0;

static int choose(int n) {
  return rand()%n;
}

static void gen(char c) {
  buf[bufp] = c;
  bufp++;
}

static void gen_num() {
  int l = choose(2);
  gen(choose(9) + '0' + 1);
  for (int i = 0; i < l; i++) {
    gen(choose(10) + '0');
  }
}

static void gen_rand_op() {
  switch (choose(3)) {
    case 0: gen('+'); break;
    case 1: gen('-'); break;
    case 2: gen('*'); break;
    case 3: gen('/'); break;
    default: assert(0);
  }
}

static void gen_rand_expr() {
  count ++;
  if (count > 2000) { gen('1'); return; }
  // buf[0] = '\0';
  switch (choose(3)) {
    case 0:
      // if (buf[bufp-1] == ')') { break; }
      gen_num();
      break;
    case 1:
      // if (buf[bufp-1] <= '9') { break; }
      gen('(');
      gen_rand_expr();
      gen(')');
      break;
    default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    // init
    bufp = 0;
    count = 0;
    gen_rand_expr();
    buf[bufp] = '\0';

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -w /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    fscanf(fp, "%d", &result);
    int r = pclose(fp);

    if (r == 0) {
      printf("%u %s\n", result, buf);
    }
  }
  return 0;
}
