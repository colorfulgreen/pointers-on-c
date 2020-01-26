/* 函数指针的两个用途：1.回调函数 2.跳转表 */

#include <stdlib.h>
#include <stdio.h>

typedef struct NODE {
    struct NODE *link;
    int value;
} Node;

/* 在一个单链表中查找一个指定值。
 * value 待查找值的指针
 * compare 比较函数的指针
 */
Node *
search_list(Node *node, void const *value,
        int (*compare)(void const *, void const *))
{
    while(node != NULL) {
        if(compare(&node->value, value) == 0)
            break;
        node = node->link;
    }
    return node;
}

int compare_ints(void const *a, void const *b)
{
    printf("%d %d\n", *(int *)a, *(int *)b);
    if(*(int *)a == *(int *)b)
        return 0;
    else
        return 1;
}

int main(void)
{
    int values[] = {1,2,3}, value = 3;
    Node *root = malloc(sizeof(Node) * 3);
    Node *prev = NULL, *node = root;
    for (int i=0; i<3; i++) {
        node->value = values[i];
        if(prev != NULL)
            prev->link = node;
        prev = node;
        node++;
    }

    node = search_list(root, &value, &compare_ints);
    if (node != NULL)
        printf("Found %d\n", node->value);
    return EXIT_SUCCESS;
}
