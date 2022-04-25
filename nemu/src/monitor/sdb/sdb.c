#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/vaddr.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) {
  return -1;
}

static int cmd_si(char *args) {
  if (args == NULL) {
    cpu_exec(1);
    return 0;
  }
  cpu_exec(atoi(args));
  return 0;
}

static int cmd_info(char *args) {
  if (args == NULL) {
    printf("info: error: no args\n");
    return 0;
  }
  if (strcmp(args, "r") == 0) {
    printf("got r\n");
    isa_reg_display();
  }
  else if (strcmp(args, "w") == 0) {
    printf("got w\n");
  }
  else {
    printf("???\n");
  }
  return 0;
}

static int cmd_x(char *args) {
  if (args == NULL) {
    printf("x: error: no args\n");
    return 0;
  }
  char *n = strtok(args, " ");
  char *e = args + strlen(n) + 1;
  if (e == NULL) {
    printf("x: error: need tow args\n");
    return 0;
  }
  bool success;
  uint32_t ans = expr(e, &success);
  // printf("n:%d, expr:%s, ans:%d, success:%d\n", atoi(n), e, ans, success);
  if (success) {
    printf("%08x: %lx", ans, vaddr_read(ans, atoi(n)));
  } else {
    printf("x: error: EXPR wrong");
  }
  return 0;
}

static int cmd_p(char *args) {
  if (args == NULL) {
    printf("p: error: no args\n");
    return 0;
  }
  return 0;
}

static int cmd_w(char *args) {
  if (args == NULL) {
    printf("w: error: no args\n");
    return 0;
  }
  return 0;
}

static int cmd_d(char *args) {
  if (args == NULL) {
    printf("d: error: no args\n");
    return 0;
  }
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display informations about all supported commands", cmd_help },
  { "h", "alias help", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "si [N] \t Run [N] step of the program, default 1", cmd_si },
  { "info", "info {rw} \t r: register info ; w: watch point info", cmd_info },
  { "x", "x <N> <EXPR> \t scan mem, begin at EXPR for N len", cmd_x },
  { "p", "p <EXPR> \t get EXPR val", cmd_p },
  { "w", "w <EXPR> \t set watch point, program stop when EXPR changed", cmd_w },
  { "d", "d <N> \t delete nember N watch point", cmd_d },

  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
