/* 字符串是一串0个或多个字符，并以位模式全0的 NUL 字节结尾。
 * C 没有显式的字符串数据类型，有几种处理方法：
 * 字符串常量 或
 * 存储于字符数组 或 
 * 存储于动态分配的内存*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    /************ 字符串长度 **********/
    /* strlen 返回值类型为 size_t，是无符号数。
     * 陷阱：size_t - size_t 仍是无符号数，是非负数。
     */
    printf("%d\n", strlen("a") - strlen("abc") >= 0); /* 1 */
    printf("%d\n", strlen("a") >= strlen("abc"));     /* 0 */

    /************ 不受限制的字符串函数 **********/
    /* 不受限制：只通过寻找字符串参数结尾的 NUL 字节来判断长度 *
     strcpy 和 strcat 返回第1个参数的一份拷贝。
     char *strcpy(char *dst, const char *src);
     char *strcat(char *s1, const char *s2);
     int *strcmp(const char *s1, const char *s2);
     */

    char message[] = "Original message";
    strcpy(message, "Hi, ");
#if 0
    /* 将侵占数组后面的部分内存空间。 */
    strcpy(message, "Different and longer message");
#endif
    strcat(message, "Wendy"); /* 连接字符串 */
    puts(message);
    printf("%d %d %d\n", 
           strcmp("a", "b"),  /* -1 */
           strcmp("a", "a"),  /*  0 */
           strcmp("b", "a")); /*  1 */

    /************ 长度受限的字符串函数 **********/
    /* 接受一个显式的 len 参数
     char *stpncpy(char *dst, const char *src, size_t len);
     注意，如果 strlen(src) < len，dst 将被额外的 NUL 字节填充到 len 长度；如果 strlen(src) >= len，只有 len 字节被复制到 dst, !!结果将不会以 NUL 字节结尾。
     */
    /* 一个错误例子: 第一行 strlen(src) = len，没有填充 NUL 字节。后面字符串结尾判定出错。*/
    strncpy(message, "Hi,", 3);  
    strncat(message, "Wendy", 6);
    puts(message);  /* Hi, WendyWendy */
    /* 补救方法是在后面手动置 NUL: buffer[BSIZE-1] = '\0' */

    /************ 字符串查找 **********/
    char string[] = "Happy New Year! N!";
    char *pc;
    pc = strchr(string, 'N');
    puts(pc); /* New Year! N! */
    pc = strrchr(string, 'N');
    puts(pc); /* N! */
    pc = strstr(string, "New");
    puts(pc); /* New Year! N! */
    /* strpbrk -- locate multiple characters in string */
    pc = strpbrk(string, "aeiou");
    puts(pc); /* appy New Year! N! */

    /* strspn, strcspn -- span a string */
    char *message2 = "\r\n    Happy New Year!";
    pc = message2 + strspn(message2, "\n\r\f\t\v ");
    puts(pc); /* Happy New Year! */
    pc = message2 + strcspn(message2, "HNY");
    puts(pc); /* Happy New Year! */

    /* 查找标记 */
    /* 警告：strtok 会修改它处理的字符串，如果源字符串不能被修改，就复制一份再传给 strtok。
    * 字符串常量不可修改，不能传给 strtok 使用. Bus error: 10 */
#if 0
    char *line = "Happy New Year!";
#endif
    char line[] = "Happy New Year!";
    static char whitespace[] = " \t\f\r\v\n";
    char *token;
    for(token = strtok(line, whitespace);
            token != NULL;
            token = strtok(NULL, whitespace))
        printf("Next token is %s\n", token);

    return EXIT_SUCCESS;

}

