#include <stdio.h>
#include <stdlib.h>

/* 用迭代计算斐波那契数 */
long
fibonacci(int n)
{
    long prev, pre_prev, v;
    v = prev = 1;

    for (; n > 2; n--) {
        pre_prev = prev;
        prev = v;
        v = pre_prev + prev;
    }
    return v;
}


int
main(void)
{
    int v;
    v = fibonacci(10);
    printf("%d\n", v);
    return EXIT_SUCCESS;
}
