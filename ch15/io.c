#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /********** 错误报告 **********/
    perror("Error message");

    /* stdin stdout stderr 是指向 FILE 结构的指针 */
    fflush(stdout);

    FILE *f = fopen("test", "r");
    if(f == NULL) {
        perror("Open test failed");
        exit(EXIT_FAILURE);
    }

    /* 字符I/O */
    /* fgetc 返回 int 为了允许函数报告文件末尾 EOF */
#if 0
    int ch;
    while((ch = fgetc(f)) != EOF)
        putchar(ch);
#endif

    /* 行I/O */
    /* fgets 当缓冲区内存储字符达到 buffer_size - 1 时停止读取 */
#if 0
    int BUFFER_SIZE = 10;
    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
    while((fgets(buffer, BUFFER_SIZE, f)) != NULL)
        printf("%s\n", buffer);
#endif

    int a, b;
    while(fscanf(f, "%d %d", &a, &b) == 2) {
        printf("%d %d\n", a, b);
    }

    if(fclose(f) != 0) {
        perror("fclose");
        exit(EXIT_FAILURE);
    }


    /********** 终止执行  **********/
    exit(EXIT_FAILURE);

    puts("Puts after exit");

    return EXIT_SUCCESS;
}
