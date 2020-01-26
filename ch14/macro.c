#include <stdlib.h>
#include <stdio.h>

/* 调试一个存在许多涉及一组变量的不同计算过程的程序 */
#define DEBUG_PRINT printf("File %s line %d:" \
        "x=%d y=%d z=%d", __FILE__, __LINE__, \
        x, y, z)

/********** 宏 **********/
/* #define 机制允许把参数替换到文本中 
 * 求值顺序的陷阱:
 * 1. (x) 加上括号，避免 SQUARE(a+1) 被替换成 a+1*a+1 */
#define SQUARE(x) ((x) * (x))
/* 2. 最外层加上括号，避免 10 * DOUBLE(a) 被替换成 10*a+a */
#define DOUBLE(x) ((x) + (x))

/* 技巧：# 把宏参数转换成字符串, 如 #argument 被预处理器翻译为 "argument" */
#define PRINT(FORMAT, VALUE) \
    printf("The value of " #VALUE \
            " is " FORMAT "\n", VALUE)

/* 技巧：## 把位于两边的符号连接成一个符号 */
#define ADD_TO_SUM(sum_number, value) \
    sum ## sum_number += value

/********** 宏与函数 **********/
/* 宏非常频繁用于执行简单的计算。因为：
 * 1. 节省程序调用开销;
 * 2. 宏是与类型无关的，可用于整型、单浮点型等。
 */
#define MAX(a, b)  ((a) > (b) ? (a) : (b))

/* 有些任务无法用函数实现。
 * 如这个宏的第2个参数是类型，无法作为函数参数传递 */
#define MALLOC(n, type) \
    ((type *)malloc((25) * sizeof(int)));


/********** 带副作用的宏参数  **********/
/* 宏参数在宏定义中出现的次数超过一次时，如果参数具有副作用，则可能出现错误。
 * 副作用指表达式求值时出现的永久性效果。
 * MAX(x++, y++) 替换成
 * ((x++) > (y++) ? (x++) : (y++))
 */
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(void)
{
    /********** 预定义符号 **********/
    printf("%s %d %s %s %d\n", __FILE__, __LINE__, __DATE__, __TIME__, __STDC__);

    /********** 宏 **********/
    printf("%d\n", SQUARE(10));

    int x = 3;
    PRINT("%d", x + 3);

    int sum5 = 5; 
    ADD_TO_SUM(5, 25);
    printf("%d\n", sum5);

    int *pi = MALLOC(25, int);
    free(pi);

    /* 副作用 */
    int a = 5, b = 8, c;
    printf("a=%d b=%d\n", a, b);
    c = MAX(a++, b++);
    printf("a=%d b=%d c=%d\n", a, b, c);

    /********** 命令行定义 **********/
    /* cc macro.c -DARRAY_SIZE=100 */
    int array[ARRAY_SIZE];
    printf("%lu\n", sizeof(array));

    return EXIT_SUCCESS;

}
