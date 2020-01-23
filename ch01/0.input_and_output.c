# if 0
    statements
# endif

// 预处理指令 preprocessor directives
#include <stdlib.h>  // EXIT_SUCCESS, EXIT_FAILURE
#include <stdio.h>
#include <string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000

// 函数原型 function prototype
int read_column_numbers(int columns[], int max);  // NOTE 数组做形参
void rearrange(char *output, char const *input, int n_columns, int const columns[]); // 无返回值的函数称为过程 procedure

int main(void)
{
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns = read_column_numbers(columns, MAX_COLS);

    /*
     * gets 
     * 输入: 标准输入
     * 功能：从标准输入读取一行文本，并把它存储于作为参数传递给它的数组中. 
     *       一行输入以换行符结束。gets 丢掉换行符并在末尾存储一个 NUL(\0) 字节。
     * 返回：非 NULL 值表示已被成功读取
     */
    while ( gets(input) != NULL ) { // NOTE 读取输入行 gets
        printf("Original input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s\n", output);
    }

    return EXIT_SUCCESS;
}


int read_column_numbers(int columns[], int max) {
    int n_columns = 0;
    int ch;  // NOTE 未初始化，初始值不可预料

    /*
     * scanf - printf 的逆操作，从标准输入读取字符并根据格式字符串进行转换
     * 输入：格式字符串，输入数据。标量前需添加 &
     * 输出：函数成功转换并存储于参数中的值的个数
     *
     * n_columns < max 用户对数组下标进行有效性检查
     * && 逻辑与；& 按位与
     *
     * -1 也被读入到了数组中，只是后面没有用
     */
    while (n_columns < max && scanf("%d", &columns[n_columns]) == 1
            && columns[n_columns] >= 0) {
        n_columns += 1;
    }

    /*
     * puts - gets 函数的输入版本，将所有字符串写到标准输出并在末尾添加一个换行符
     */
    if (n_columns % 2 != 0) {
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }

    /* scanf 只读取了需要的字符，这里读取并丢弃剩余字符，防止它们被当作第一行数据解析 */
    /* ch 是一个整型，因为 EOF 是一个整型 */
    while ((ch = getchar()) != EOF && ch != '\n')
        ;  // ; 单独成行，空语句，避免后续语句被误认为循环体一部分。

    return n_columns;
}


/* 数组的参数传递：
 * 1. output 和 input 被声明为指针，但实际调用时传递他们的是数组名。
 *    函数可以按照操纵指针的方式来操纵实参，也可以像数组名一样用下标来引用数组的元素。
 * 2. int const columns[] 数组中的元素不能修改
 *
 */
void rearrange(char *output, char const* input, int n_columns, int const columns[]) {
    int col;
    int output_col;
    int len;
    
    len = strlen(input);
    output_col = 0;

    for (col = 0; col < n_columns; col += 2) {
        int nchars = columns[col + 1] - columns[col] + 1;
        // 输入行结束 或 输出行已满
        if (columns[col] >= len ||
                output_col == MAX_INPUT - 1) // 为什么正好是 MAX_INPUT - 1 ? 因为下方语句对 nchars 和 output_col 做了修正
            break;
        if (output_col + nchars > MAX_INPUT -1)
            nchars = MAX_INPUT - output_col - 1;

        // NOTE char *strncpy（s, ct, n）, 将字符串ct中最多n个字符复制到字符串s中，并返回s。如果ct中少于n个字符，则用‘\0’填充。
        strncpy(output + output_col, input + columns[col], nchars);  // NOTE strncpy
        output_col += nchars;
    }

    output[output_col] = '\0';

}
