#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define N_VALUES 5

size_t my_strlen(char *string) {
    int length = 0;
    while (*string++ != '\0')
        length += 1;
    return length;
}


/* TODO caller */
/* strings 使用指针数组来表示一组字符串，以 NULL 结束 */
int find_char(char **strings, char value) {
    char *string;
    /* while ((string = *strings++) != NULL)
     * 1. 把 strings 当前所指向的指针复制到 string 中
     * 2. 增加 strings 的值，使其指向下一个值
     * 3. 测试 string 是否为 NULL
     */
    while ((string = *strings++) != NULL) {
        while (*string != '\0') {
            if (*string++ == value)
                return TRUE;
        }
    }
    return FALSE;
}


int main(void) {
    /*************** 未初始化的指针 wrong ******************/
    /* 声明一个指向整型的指针不会“创建”用于存储整型值的内存空间。 
     * 不能对未初始化的指针进行间接的访问操作 */
#if 0
    int *p;
    *p = 300;
    printf("%d\n", *p);
#endif

    /*************** 指针的指针 ******************/
    /* *操作符具有自右向左的结合性，**c 相当于 *(*c) */
    int a = 12;
    int *b = &a;
    int **c = &b;
    printf("%d\n", **c);

    /*************** 指针表达式 ******************/
    /* 回顾：左值和右值出现在赋值符号左右。左值标识了可以存储结果的位置；右值是一个数值。*/
    /* 指针加法 cp+1 的结果是个右值，因为其存储位置未清晰定义。 ?
       但加上间接访问操作符后 *(cp+1) 可以作为左值使用。 (这里的写法是非法的) */
    char ch = 'a';
    char *cp = &ch;
    *(cp + 1) = 'c';
    printf("%c\n", *(cp+1));
    /* ++cp 和 cp++ 分别返回指针增值后的一份拷贝 和 cp 的一份拷贝，拷贝的存储位置未定，不能作为左值。
     * 但加上间接访问后 *(++cp) 可以作为左值，即 ch 后内存地址的位置。
     */

    char *string = "Happy New Year!";
    // printf("%lu\n", my_strlen(string));

    /*************** 指针算数运算 ******************/
    float ff[4] = {3.14, 2.71828, 1.414, 0.5};
    float *pf = &ff[0];

    /* 1. 指针 + 整数 */
    /* pf+2 使指针的值增加3个 float 的大小，而不是3个字节 */
    printf("%f\n", *(pf+2));
    /* 把数组中所有元素初始化为 0。
     * 注意：让指针指向数组最后一个元素后面的那个位置是合法的，但是不能执行间接访问。
     */
    int values[N_VALUES];
    int *vp;
    for( vp=&values[0]; vp < &values[N_VALUES]; )
        *vp++ = 0;
    /* 注意：标准允许指向数组元素的指针与指向数组最后一个元素后面那个内存元素的指针比较，
     * 但不允许与指向数组第一个元素之前位置的指针比较。
     */
#if 0 
    for (vp=&values[N_VALUES - 1]; vp > &values[0]; vp--)
        *vp = 0;
#endif

    /* 2. 指针 - 指针，前提：两个指针都指向同一数组中的元素 
     * 结果类型是 ptrdiff_t，值是两个指针在内存中的距离，以数组元素的长度为单位
     */

    /*************** 指针关系运算 ******************/
    /* 关系运算符 > >= < <= 可用于指针，前提是它们指向同一个数组中的元素 */

    return EXIT_SUCCESS;
}
