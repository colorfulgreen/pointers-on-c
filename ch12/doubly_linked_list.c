#include <stdlib.h>
#include <stdio.h>

typedef struct NODE {
    struct NODE *fwd;
    struct NODE *bwd;
    int value;
} Node;


int
dll_insert(register Node *rootp, int value)
{
    register Node *this;
    register Node *next;
    register Node *newnode;

    /* 双链表使用了一个 root 结点, 初始状态 fwd 和 bed 为 NULL, value 值没有使用 */
    for(this = rootp; (next = this->fwd) != NULL; this = next) {
        if( next->value == value)
            return 0;
        if( next->value > value)
            break;
    }

    newnode = (Node *)malloc(sizeof(Node));
    if(newnode == NULL)
        return -1;
    newnode->value = value;

    newnode->fwd = next;
    this->fwd = newnode;

    if(this != rootp)
        newnode->bwd = newnode;
    else
        rootp->bwd = newnode;

    return 1;
}
