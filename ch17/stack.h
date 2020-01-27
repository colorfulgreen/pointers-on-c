#include <stdlib.h> /* size_t */

#define STACK_TYPE int

void push(STACK_TYPE value);
void pop(void);
STACK_TYPE top(void);
int is_empty(void);
int is_full(void);

/* 仅动态数组方案使用 */
void create_stack(size_t size);
void destroy_stack(void);


