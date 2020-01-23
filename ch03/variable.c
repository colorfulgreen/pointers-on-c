#include <stdio.h>
#include <stdlib.h>

int main(void) {

    /*****************字符串常量和数组***************************/

# if 0
    /* 不能把字符串常量赋值给字符数组 */
    const char *string = "Happya New Year! - String";
    char array[50];
    array = string;
# endif

    /* 但字符数组可以用字符串常量初始化 */
    char array2[] = "Happy New Year!";
    puts(array2);

    /*********************指针声明与初始化***************************/

    /* 星号是表达式 *b 的一部分，只对这个标识符有用。*/
    int *b, c = 10;
    b = &c;
    printf("%d\n", *b);

    int *a = malloc(sizeof(int));
    *a = 10;
    printf("%d\n", *a);

    /* 初始值赋给 message 本身，而不是给 *message 。下面两种方法等价。*/
    char *message = "Happy New Year!";
    printf("%s\n", message);

    char *message2;
    message2 = "Happy New Year!";
    printf("%s\n", message2);

    /********************* typedef ***************************/

    /* typedef 为数据类型定义新名字，声明写法和普通声明类似，只是把 typedef 这个关键字写在前面。*/
    typedef char *pointer_to_char;
    pointer_to_char pc;
    pc = "Happy New Year! typedef";
    printf("%s\n", pc);

# if 0
    /* 应使用 typedef 而不是 #define 来创建新的类型名，因为后者无法正确处理指针。 
     * 下列语句正确声明了 a, 但 b 被声明为一个字符. */
    # define d_ptr_to_char char *
    d_ptr_to_char da, db;
# endif

    /********************* 常量和指针 ***************************
     * 星号前面的部分是指针指向的内容。
     */

    int aaa = 1, bbb = 2;
    /* 指向整型常量的指针，可以修改指针的值，但不能修改它所指向的值。 */
    int const *pa = &aaa; 
    pa = &bbb;
    /* *pa = 2; 错误 */
    /* 指向整型的常量指针，不可以修改指针的值，可以修改它所指向的值。*/
    int * const pb = &bbb;
    *pb = 3;
    /* pb = &aaa; 错误 */

    /********************* 两种声明常量的方法 *****************
     * #define 允许使用字面值常量的地方都能使用，比如声明数组的长度
     * const 只能用于允许使用变量的地方
     */

    #define MAX_ELEMENTS 50
    int const max_elements = 50;


    return EXIT_SUCCESS;
}
