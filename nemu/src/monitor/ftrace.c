#include <isa.h>
// #include <elf.h>

typedef struct {
  char name[32];
  word_t addr;
  int size;
} Func;

static Func funcs[128];
static int funcs_len = 0;

static uint8_t fstack[512];    // stack record, use funcs index
static int point = 0;

void init_ftrace(const char *elf_file) {
  if (elf_file == NULL)
    return;
  FILE *fp;
  char buffer[80];
  fp = popen(strcat("readelf -e", elf_file), "r");
  while (fgets(buffer, sizeof(buffer), fp) != 0) {
    if (buffer[31] == 'F' && buffer[32] == 'U' && buffer[33] == 'N') {
      funcs[funcs_len].addr = strtoul(buffer+8, NULL, 16);
      funcs[funcs_len].size = strtoul(buffer+24, NULL, 10);
      strcpy(funcs[funcs_len].name, buffer+59);
      funcs[funcs_len].name[strlen(buffer+59)-1] = '\0'; // clean \n
      printf("%s, %lx, %d\n", funcs[funcs_len].name,
        funcs[funcs_len].addr, funcs[funcs_len].size);
      funcs_len ++;
    }
  }
}

void call_trace(word_t call_addr, word_t f_addr) {
  printf("%08lx: ", call_addr);
  for (int i = 0; i < funcs_len; i++) {
    if (f_addr == funcs[i].addr) {
      for (int j = 0; j < point; j++) {
        printf("%s", "  ");
      }
      printf("call [%s@%08lx]\n", funcs[i].name, funcs[i].addr);

      fstack[point] = i;
      point ++;
      return;
    }
  }
  assert(0);
}


void ret_trace(word_t call_addr) {
  printf("%08lx: ", call_addr);
  point --;
  for (int j = 0; j < point; j++) {
    printf("%s", "  ");
  }
  printf("ret  [%s]", funcs[fstack[point]].name);
}
