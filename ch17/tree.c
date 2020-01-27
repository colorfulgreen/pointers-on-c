/* 用静态数组实现的二叉搜索树。为了便于计算下标，第0个元素不用。  */
#include "tree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE + 1)

static TREE_TYPE tree[ARRAY_SIZE];

static int left_child(int current)
{
    return current * 2;
}

static int right_child(int current)
{
    return current * 2 + 1;
}

void insert(TREE_TYPE value)
{
    int current;

    assert(value != 0);
    current = 1;
    while(tree[current] != 0) {
        if(value < tree[current])
            current = left_child(current);
        else {
            /* 不允许重复插入相同节点 */
            assert(value != tree[current]);
            current = right_child(current);
        }
        assert(current < ARRAY_SIZE);
    }
    tree[current] = value;
}

TREE_TYPE * find(TREE_TYPE value)
{
    int current;
    current = 1;
    while(current < ARRAY_SIZE && tree[current] != value) {
        if(value < tree[current])
            current = left_child(current);
        else
            current = right_child(current);
    }
    if(current < ARRAY_SIZE)
        return tree + current;
    else
        return 0;
}

/* 前、中、后序遍历，指根结点在前、中、后 */
static void do_pre_order_traverse(int current, 
        void (*callback)(TREE_TYPE value)) 
{
    if(current < ARRAY_SIZE && tree[current] != 0) {
        callback(tree[current]);
        do_pre_order_traverse(left_child(current), callback);
        do_pre_order_traverse(right_child(current), callback);
    }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
    do_pre_order_traverse(1, callback);
}

void p(TREE_TYPE value) 
{
    printf("%d\n", value);
}

int main(void)
{
    insert(5);
    insert(3);
    insert(8);
    insert(12);
    insert(2);
    pre_order_traverse(&p);

    return EXIT_SUCCESS;
}
