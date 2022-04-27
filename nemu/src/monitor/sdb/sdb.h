#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>

word_t expr(char *e, bool *success);

typedef struct watchpoint WP;
WP* new_wp(char *exp, word_t val);
bool free_wp(int no);
WP* get_wp(int no);
void wp_info(WP *wp);
void wp_display();
bool wp_check();

#endif
