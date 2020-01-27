/* 用静态数组实现队列。尾部插入，头部删除。 */
/* 为了在循环数组中判断空满，有1个元素始终保留不用 */
#include "queue.h"
#include <stdio.h>
#include <assert.h>

#define QUEUE_SIZE 10
#define ARRAY_SIZE (QUEUE_SIZE + 1)

static QUEUE_TYPE queue[ARRAY_SIZE];
static size_t front = 1;
static size_t rear = 0;

void insert(QUEUE_TYPE value)
{
    assert(!is_full());
    rear = (rear + 1) % ARRAY_SIZE;
    queue[rear] = value;
}

void delete(void)
{
    assert(!is_empty());
    front = (front + 1) % ARRAY_SIZE;
}

QUEUE_TYPE first(void)
{
    assert(!is_empty());
    return queue[front];
}

int is_empty(void)
{
    return (rear + 1) % ARRAY_SIZE == front;
}

int is_full(void)
{
    return (rear + 2) % ARRAY_SIZE == front;
}

int main(void)
{
    insert(3);
    insert(3);
    insert(3);
    insert(3);
    insert(3);
    insert(3);
    insert(3);
    delete();
    delete();
    delete();
    delete();
    delete();
    delete();
    delete();
    printf("%lu %lu", rear, front);
}
