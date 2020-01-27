/* 使用动态分配的链式结构实现的二叉搜索树 */
#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TREE_NODE {
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
} TreeNode;

static TreeNode *tree;

void insert(TREE_TYPE value)
{
    TreeNode *current;
    /* link 指向待插入节点，即父节点的 left 或 right */
    TreeNode **link;

    link = &tree;
    while((current = *link) != NULL){
        if(value < current->value)
            link = &current->left;
        else {
            assert(value != current->value);
            link = &current->right;
        }
    }

    current = malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}

TREE_TYPE *find(TREE_TYPE value)
{
    TreeNode *current;
    current = tree;
    while(current != NULL && current->value != value) {
        if(value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if(current != NULL)
        return &current->value;
    else
        return NULL;
}

static void do_pre_order_traverse(TreeNode *current,
        void (*callback)(TREE_TYPE value))
{
    if(current != NULL){
        callback(current->value);
        do_pre_order_traverse(current->left, callback);
        do_pre_order_traverse(current->right, callback);
    }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
    do_pre_order_traverse(tree, callback);
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
