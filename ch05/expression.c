#include <stdio.h>
#include <stdlib.h>

int main( void ) {
    /**************** 左值 L-value 和右值 R-value ****************/
    int i, j = 0, *pi;
    int a[5] = {0,1,2,3,4};
    pi = &i;

    /* 左值：出现在赋值符号左边，标识了可以存储结果的地点。部分操作符如直接引用和下标操作的结果是左值。*/
    /* 右值：出现在赋值符号右边。 大部分操作符的结果是右值。 */
    i = j + 1;
    *pi = 5;
    a[j + 1] = 100;
    printf("%d %d\n", i, a[j + 1]);


    return EXIT_SUCCESS;
}
