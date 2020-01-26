#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *
strdup(char const *string)
{
    char *new_string;

    /* strlen 不计算最后一个 NUL 字节 */
    new_string = malloc(strlen(string) + 1);

    if(new_string != NULL)
        strcpy(new_string, string);

    return new_string;
}


int 
main(void)
{
    /* 
       void *malloc(size_t size);
       - size: 需要分配的字节数
       -  成功返回指向内存的 void *，失败返回 NULL。必须对每个从 malloc 返回的指针进行检查。
       void free(void *pointer);

     */
    char *p = malloc(25 * sizeof(char));
    if (p != NULL) {
        strcpy(p, "Happy New Year!");
        puts(p);
        free(p);
    }

    /*
    void *calloc(size_t count, size_t size);
    - 参数：需要的元素数量，每个元素的字节数
    - calloc 在返回指向内存的指针之前将其初始化为 0

    void *realloc(void *ptr, size_t size);
    - 功能：修改已分配的内存块的大小。
    - 使用 realloc 后不能在使用指向旧内存的指针，而是改用 realloc 所返回的新指针。
    */

    /* demo: 制作字符串的拷贝 */
    char *p1 = strdup(p);
    if (p1 != NULL) {
        puts(p1);
        free(p1);
    }
    return EXIT_SUCCESS;
}
