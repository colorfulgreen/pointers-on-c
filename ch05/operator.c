#include <stdlib.h>
#include <stdio.h>

/* 用右移操作计算一个数中值为1的个数 */
int counts_one_bit(unsigned value) {
    int ones;
    for (ones = 0; value != 0; value = value >> 1) {
        // if (value % 2 != 0) 
        if ((value & 1) != 0) 
            ones += 1;
    }
    return ones;
}


int main(void) {

    /****************** 移位操作 ************************
     * 标准说明无符号数的移位是逻辑移位，未说明有符号数的移位。
     * 一个程序如果使用了有符号数的移位操作，就不是可移植的。
     */
    unsigned int a = 32;
    int b = -32;
    printf("%d %d\n", a >> 2, b >> 2);
    printf("%d\n", counts_one_bit(255));

    /****************** 位操作符 ************************/
    /* 或，与，异或 */
    printf("%d %d %d\n", 1|2, 1&3, 1^2);

    /* 把指定的位设置为 1 */
    printf("%d\n", 128 | 1 << 6); 
    /* 把指定的位清 0 */
    printf("%d\n", 192 & ~(1 << 6)); 
    /* 测试指定的位 */
    printf("%d\n", 192 & 1 << 7);

    /****************** 单目操作符 ************************/
    /* ! 逻辑反，产生整型结果 0 或 1 */
    printf("%d %d\n", !123, !0);
    /* ~ 求补，按位取反 */
    short c = 65530;
    printf("%d\n", ~c);

    /****************** 关系操作符 ************************/
    /* C 用整数来表示布尔值，这产生了一些简写写法。下方每组等价。 */

    int expression = 5;
    if ( expression != 0 )
        printf("True\n");
    if ( expression )
        printf("True\n");

    if ( expression == 0 )
        printf("False\n");
    if ( !expression )
        printf("False\n");

    /****************** 逻辑操作符 ************************/
    /* && 和 || ，短路求值 short-curcuited evaluation */
    int x = 1;
    char array[] = "Hello";
    if (x >= 0 && x < sizeof(array) && array[x] == 'e')
        printf("e\n");

    /****************** 条件操作符 ************************/
    int ax = 6, bx;
    bx = ax > 5 ? 3 : -10;
    printf("%d\n", bx);
    
    /****************** 逗号操作符 ************************
     * 自左向右逐个求值，整个表达式的值是最右那个表达式的值
     * while (a = get_value(), count_value(a), a > 0) {}
     */

    /************* 下标引用 等价于 间接访问表达式 *********/
    char array2[] = "Happy New Year!";
    printf("%c %c\n", array2[2], *(array2 + 2));

    return EXIT_SUCCESS;

}
