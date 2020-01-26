#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    /************ 结构声明 ************/
    /* struct tag {member-list} variable-list */

    /* 方法1 为成员列表提供一个 tag，后续使用 */
    struct SIMPLE {
        int a;
        char b;
        float c;
    };
    struct SIMPLE x, y[20], *z;

    /* 方法2 用 typedef 创建一个新的类型 */
    typedef struct {
        int a;
        char b;
        float c;
    } Simple;
    Simple x1, y1[20], *z1;

    /************ 结构成员的直接访问 ************/
    /* 下标引用和点操作符有相同的优先级，结合性都是从左向右 */
    x.a = 10;

    /************ 结构成员的间接访问 ************/
    z = &x;
    /* 点操作符的优先级高于间接访问操作符，必须使用括号使间接访问先执行  */
    printf("%d\n", (*z).a);
    /* C提供了更方便的 -> 操作符 */
    printf("%d\n", z->a);

    /************ 结构的自引用 ************/

    /* 陷阱：结构内部包含自己的成员是非法的 */
#if 0
    struct SELF_REF1 {
        int a;
        struct SELF_REF1 b;
    };
#endif

    /* 但可以包含指向结构本身的指针，因为编译器可以确定指针的长度 */
    struct SELF_REF2 {
        int a;
        struct SELF_REF2 *b;
    };

    /* 陷阱：用 typedef 为结构创建类型名时，类型名直到结尾才定义。在结构声明的内部尚未定义 
     * 解决方法是定义一个结构标签
     */
#if 0
    typedef struct {
        int a;
        struct SELF_REF3 *b;
    } SELF_REF3;
#endif

    /************ 结构的初始化 ************/
    struct INIT_EX {
        int a;
        short b[10];
        Simple c;
    } ex = {
        10,
        {1,2,3,4,5},
        {25, 'x', 1.9}
    };
    struct INIT_EX *pex = &ex;
    int *pi;
    /* -> 操作符的优先级高于 & 操作符的优先级 */
    pi = &pex->a;
    printf("%d\n", *pi);
    /* -> 操作符的优先级高于 * 操作符的优先级 */
    printf("%d\n", *pex->b); /* 数组b的第一个元素 */

    /************ 结构的存储分配 ************/
    /* 编译器按成员列表顺序为成员分配内存空间，成员需满足边界对其要求 */
    struct ALIGN {
        char a;
        int b;
        char c;
    } align;
    printf("%lu\n", sizeof(align)); /* 12 */
    /* 可以在声明中对结构的成员列表重新排列，让对边界要求最严格的成员首先出现，减少因边界对齐带来的空间损失。 */
    struct ALIGN2 {
        int b;
        char a;
        char c;
    } align2;
    printf("%lu\n", sizeof(align2)); /* 8 */

    /************ 作为函数参数的结构 ************/
    /* 结构变量是一个标量，可作为参数传递给一个函数。
     * 但效率很低，因为C语言的参数传值方式要求把参数的一份拷贝传递给函数。
     * 一般传递指向结构的指针。
     */

    return EXIT_SUCCESS;

}
