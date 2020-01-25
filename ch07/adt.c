#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt.h"

/* 限制对模块的访问是通过 static 关键字的合理使用实现的。 
 * static 关键字用于函数定义或代码块之外的变量声明时，将标识符的链接属性从 external 改为 internal，但存储类型和作用域不受影响。只能在声明其的源文件中访问。
 */
static char name[MAX_ADDRESSES][NAME_LENGTH];
static char address[MAX_ADDRESSES][ADDR_LENGTH];

static int
find_entry(char const *name_to_find)
{
    int entry;
    for(entry = 0; entry < MAX_ADDRESSES; entry += 1)
        if(strcmp(name_to_find, name[entry]) == 0)
            return entry;
    return -1;
}

char const *
lookup_address(char const *name)
{
    int entry;
    entry = find_entry(name);
    if(entry == -1)
        return NULL;
    else
        return address[entry];
}

int main(void) {
    return EXIT_SUCCESS;
}
