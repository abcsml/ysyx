#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char exp[64]; // maybe a bug
  word_t val;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
// 获取一个free节点，并赋值，如果失败就painc
WP* new_wp(char *exp, word_t val) {
  if (free_->next == NULL) {
    assert(0);
  }
  WP *p = free_;
  free_ = free_->next;

  int n = strnlen(exp, 63);
  strncpy(p->exp, exp, n);
  p->exp[n] = '\0';
  p->val = val;

  p->next = head;
  head = p;
  return p;
}

bool free_wp(int no) {
  WP *wp = NULL;
  if (head->NO == no) {
    wp = head;
    head = head->next;
  }
  else {
    WP *p = head;
    while (p->next != NULL) {
      if (p->next->NO == no) {
        wp = p->next;
        p->next = p->next->next;
        break;
      }
      p = p->next;
    }
  }
  
  if (wp == NULL) {
    return false;
  }
  wp->next = free_;
  free_ = wp;
  return true;
}

WP* get_wp(int no) {
  WP *p = head;
  while (p != NULL) {
    if (p->NO == no) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

// 打印节点信息
void wp_info(WP *wp) {
  printf("wp:%02d , expr:%s , val:0x%lx\n", wp->NO, wp->exp, wp->val);
}

void wp_display() {
  WP *p = head;
  while (p != NULL) {
    wp_info(p);
    p = p->next;
  }
}

// 返回是否有变化，打印有变化节点信息，并更新节点
bool wp_check() {
  bool c = false;
  WP *p = head;
  while (p != NULL) {
    bool succ;
    word_t v = expr(p->exp, &succ);
    if (succ == false) {
      printf("wp:%d , EXPR wrong\n", p->NO);
    }
    else if (p->val != v) {
      p->val = v;
      wp_info(p);
      c = true;
    }
    p = p->next;
  }
  return c;
}
