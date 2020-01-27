/* 用静态数组实现堆栈 */
#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 100

static STACK_TYPE stack[STACK_SIZE];
static int top_element = -1;

void push(STACK_TYPE value)
{
    assert(!is_full());
    top_element += 1;
    stack[top_element] = value;
}

void pop(void) 
{
    assert(!is_empty());
    top_element--;
}

#if 0
STACK_TYPE pop(void) 
{
    assert(!is_empty());
    /* 注意操作顺序，先复制元素，然后减1。和 push 相反。 */
    return stack[top_element--];
}
#endif

STACK_TYPE top(void)
{
    assert(!is_empty());
    return stack[top_element];
}

int is_empty(void)
{
    return top_element == -1;
}

int is_full(void)
{
    return top_element == STACK_SIZE -1;
}

int main(void)
{
    push(5);
    push(6);
    STACK_TYPE a, b;
    a = top();
    pop();
    b = top();
    pop();
    printf("%d %d %d\n", a, b, is_empty());

    return EXIT_SUCCESS;
}
