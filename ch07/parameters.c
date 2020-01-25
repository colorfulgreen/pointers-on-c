#include <stdio.h>
#include <stdlib.h>

/* 奇偶性校验
 * 传值调用，传递的是实际参数的一份拷贝。
 * 函数执行过程中会破坏 value 和 n_bits 两个参数的值。但破坏的是拷贝，不影响原先的值。
 */
int even_parity(int value, int n_bits)
{
    int parity = 0;

    while( n_bits > 0) {
        parity += value & 1;
        value >>= 1;
        n_bits -= 1;
    }

    printf("%d %d %d\n", value, n_bits, parity);

    /* 最低位为 0 即偶数返回 True */
    return (parity % 2) == 0;
}


/* 整数交换，必须传递希望修改变量的指针 */
void swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}


/* 把数组所有元素都设置为0.
 * 声明数组参数时不指定它的长度是合法的，因为函数不为其分配内存。数组参数的值是一个指针拷贝。
 */
void clear_array(int array[], int n_elements) 
{
    while(n_elements > 0)
        array[--n_elements] = 0;
}


int main(void) 
{
    int value = 12, 
        n_bits = 5,
        parity;
    parity = even_parity(value, n_bits);
    printf("%d %d %d\n", value, n_bits, parity);

    int x=1, y=2;
    swap(&x, &y);
    printf("%d %d\n", x, y);

    int array[3] = {0,1,2};
    clear_array(array, 3);

    return EXIT_SUCCESS;
}
