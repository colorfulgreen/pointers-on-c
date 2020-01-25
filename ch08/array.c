#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
lookup_keyword(char const * const desired_word,
        char const *keyword_table[])
{
    char const **kwp;
    for(kwp = keyword_table; *kwp != NULL; kwp++)
    {
        if(strcmp(desired_word, *kwp) == 0)
            return kwp - keyword_table;
    }
    return -1;
}


void
my_strcpy(char *buffer, char const *string)
{
    /* 数组名作为函数参数，函数得到的是指针的一份拷贝。 
     * 虽然里修改了 string，但不会影响调用程序的实参，因为只有拷贝被修改了。
     */
    while ((*buffer++ = *string++) != '\0')
        ;
}

void
print_matrix(int mat[][10], int n_rows)
{
    while(n_rows-- > 0){
        for(int i=0; i<10; i++) {
            printf("%d ", (*mat)[i]);
        }
        printf("\n");
        mat++;
    }
}

int main(void)
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int b[10];
    int *c;

    /********* 数组名是什么？ ************/
    /* 1. 数组和指针不同。
     * 1) 数组有确定数量的元素，而指针只是一个标量值。 
     * 2) 声明一个数组时，编译器根据声明指定的元素数量为数组保留内存空间。声明一个指针变量时，只为指针本身保留内存空间。
     * 上述声明后，*b 合法，*c 非法
     */
    printf("%lu\n", sizeof(b));

    /* 2. 只有当数组名在表达式中使用时，编译器才会为其生成一个指针常量。
     * 注意数组名是指针常量，不是指针变量，不能修改。
     * 以下两条指令都是非法的：
     */
#if 0
    a = b;
    a++;
#endif

    /* 3. 只有在两种情况下，数组名不能用指针常量来表示。
     * 1) sizeof 返回整个数组的长度，而非指针长度
     * 2) & 产生指向数组的指针，而不是指向指针常量值的指针。
     */
    printf("%lu %lu\n", sizeof(a), sizeof(*(&a)));

    /********* 下标引用 ************/
    int *ap = a + 2;
    /* C 的下标引用和间接访问表达式相同 */
    printf("%d %d\n", *ap, ap[0]);

    /********* 作为函数参数的数组名 ************/
    char stra[10], strb[10] = "Hello"; 
    my_strcpy(stra, strb);
    printf("%s\n", stra);

    /* 下面两个函数原型是相等的。指针的写法“更加准确” */
    int my_strlen(char *string);
    int my_strlen(char string[]);

    /********* 字符数组 和 字符串常量 ************/
    /* 初始化一个字符数组 h,e,l,l,o,0 */
    char message1[] = "Hello";
    /* 字符串常量指针 */
    char *message2 = "Hello"; 
    printf("%s %s\n", message1, message2);

    /********* 多维数组 ************/
    /* 数组元素的存储顺序是行主序，即按照最右边的下标率先变化的原则 */
    int matrix[3][10];
    int *mp;
    for(int i=0; i<3; i++)
        for(int j=0; j<10; j++)
            matrix[i][j] = i * 10 + j;
    mp = &matrix[1][8];
    printf("%d\n", *mp);   /* matrix[1][8] */
    printf("%d\n", *++mp); /* matrix[1][9] */
    printf("%d\n", *++mp); /* matrix[2][0] */

    /* 多维数组的下标仍然等同于间接访问 */
    /* matrix + 1 指向包含10个整型元素的子数组 matrix[1]，即 matrix 的第一行 */
    printf("%lu %lu\n", sizeof(matrix[1]), sizeof(*(matrix+1))); /* 40 40 */

    /* 指向整型数组的指针 */
    /* p 指向 matrix 的第 1 行 , p++ 指向第二行*/
    int (*p)[10] = matrix;
    printf("%lu\n", sizeof(p)); /* 8 */
    printf("%d\n", (*p)[5]); /* matrix[0][5] */
    p++;
    printf("%d\n", (*p)[5]); /* matrix[1][5] */

    /* 指向整型元素的指针 */
    int *pi = matrix[0];
    printf("%d\n", *pi); /* matrix[0][0] */
    pi++;
    printf("%d\n", *pi); /* matrix[0][1] */

    /********* 作为函数参数的多维数组 ************/
    /* 参数 matrix 的类型是指向包含 10 个整型元素的数组的指针,
     * 函数原型可使用以下两种形式中的任意一种。注意：
     * 编译器必须知道第2个及以后各维的长度才能对下标进行求值，因此在函数原型中必须表明这些维的长度。第1维的长度并不需要，因为计算下标时用不到它。
     */
    void func1(int (*mat)[10]);
    void func2(int mat[][10]);
    print_matrix(matrix, 3);
    /* 下面这种写法是错的。它把 mat 声明为指向整型指针的指针，它和指向整型数组的指针不是一回事。 */
    void func3(int **mat);

    /********* 多维数组初始化 ************/
    /* 1. 只给出一个初始值列表，存储顺序按最右边的下标率先变化的原则确定 
     * 2. 基于多维数组实际上是复杂元素的一维数组
     */

    int matrix2[2][3] = {100, 101, 102, 110, 111, 112};
    printf("%d\n", matrix2[1][0]);
    int matrix3[2][3] = {
        {100, 101, 102}, 
        {110, 111, 112},
    }; 
    printf("%d\n", matrix3[1][0]);
    /* 不完整的初始化列表 */
    int matrix4[2][3] = {
        {100}, 
        {110},
    }; 
    printf("%d %d\n", matrix4[1][0], matrix4[1][1]);
   /* 数组长度自动计算。多维数组中只有第1维才能根据初始化列表缺省提供，剩余几个维必须显示地写出。 */ 
    int matrix5[][3] = {
        {100, 101}, 
        {110},
    }; 


    /********* 指针数组 ************/
    /* 方法：为了弄清复杂的声明，假定它是一个表达式，并对它进行求值。 
     * 下标引用的优先级高于间接访问，首先执行下标引用，
     * 得出 api 是个数组，其元素类型是指向整型的指针。
     */
    int *api[10];

    /* 指针数组的应用：查找关键字索引  */
    char const *keyword[] = {
        "do",
        "for",
        "if",
        "register",
        "return",
        "switch",
        "while",
        NULL
    };
    int index;
    index = lookup_keyword("register", keyword);
    printf("%d\n", index);


}
