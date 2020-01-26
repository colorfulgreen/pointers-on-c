#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* 联合的所有成员引用的是内存中的相同位置。 */
    /* 例子：解释器记录一个变量的类型和值 */
    struct VARIABLE {
        enum {INT, FLOAT, STRING} type;
        union {
            int i;
            float f;
            char *s;
        } value;
    };
    struct VARIABLE v;
    v.value.i = 1;
    v.type = INT;
    if (v.type == int)
        printf("%d\n", v.value.i);

    /* 内存：分配给联合的内存数量取决于它的最长成员的长度。
     * 如果成员长度相差悬殊，更好的办法是在联合中存储指向不同成员的指针。
     */

    /* 联合变量可以初始化，但初始值必须是联合的第1个成员的类型 */

    return EXIT_SUCCESS;
}
