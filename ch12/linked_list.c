#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE  1

typedef struct NODE {
    struct NODE *link;
    int value;
} Node;


/* 插入到一个有序单链表。
 * rootp: 传递根指针以便给第一个位置插入元素 
 */
int sll_insert(Node **rootp, int new_value)
{
    Node *current;
    Node *previous; /* 单向链表，保留 previous */
    Node *new;

    current = *rootp;
    previous = NULL;

    while (current != NULL && current->value < new_value) {
        previous = current;
        current = current->link;
    }

    new = (Node *)malloc(sizeof(Node));
    if(new == NULL)
        return FALSE;
    new->value = new_value;

    new->link = current;
    if(previous == NULL)
        *rootp = new;
    else
        previous->link = new;

    return TRUE;
}


/* TODO
 * 改进版：消除特殊情况。
 * 链表中的每个节点都有一个指向它的指针。该指针是否位于一个节点的内部无关紧要。借助这点，不需要对 root 做特殊处理。
 */
int sll_insert2(register Node **linkp, int new_value)
{
    register Node *current;
    register Node *new;

    while((current = *linkp) != NULL &&
            current->value < new_value)
        linkp = &current->link;

    new = (Node *)malloc(sizeof(Node));
    if(new == NULL)
        return FALSE;
    new->value = new_value;

    new->link = current;
    *linkp = new;
    return TRUE;
}

/* TODO 链表初始化 */
int main(void)
{
    int values[] = {1,3,5,10};
    int n_values = sizeof(values) / sizeof(int);
    Node *root = malloc(n_values * sizeof(Node));
    Node *p = root;
    Node *prev = NULL;

    for(int i=0; i<n_values; i++) {
        p->value = values[i];
        if(prev != NULL)
            prev->link = p;
        prev = p;
        p++;
    }

    sll_insert2(&root, 7);
}
