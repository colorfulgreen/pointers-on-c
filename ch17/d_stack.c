/* 用动态数组实现堆栈 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static STACK_TYPE *stack;
static size_t stack_size;
static int top_element = -1;

void create_stack(size_t size)
{
    assert(stack_size == 0);
    stack_size = size;
    stack = malloc(stack_size * sizeof(STACK_TYPE));
    assert(stack != NULL);
}

void destroy_stack(void)
{
    assert(stack_size > 0);
    stack_size = 0;
    free(stack);
    stack = NULL;
}

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

STACK_TYPE top(void)
{
    assert(!is_empty());
    return stack[top_element];
}

int is_empty(void)
{
    assert(stack_size > 0);
    return top_element == -1;
}

int is_full(void)
{
    assert(stack_size > 0);
    return top_element == stack_size - 1;
}

int main(void)
{
    create_stack(10);
    push(5);
    push(6);
    STACK_TYPE a, b;
    a = top();
    pop();
    b = top();
    pop();
    printf("%d %d %d\n", a, b, is_empty());

    destroy_stack();

    return EXIT_SUCCESS;
}
