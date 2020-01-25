#include <stdlib.h>
#include <stdio.h>
#include "prototype.h"

/* 所有函数都应当具有原型，尤其是返回值不是整型的函数。
 * 因为编译器默认函数将返回一个整型值，对于返回非整型值的函数，这种隐式认定可能导致错误的类型转换。 
 * float f;
 * f = xyz();
 */

int *find_int(int key, int array[], int array_len) 
{
    int i;

    for (i=0; i < array_len; i += 1)
        if (array[i] == key)
            return &array[i];

    return NULL;
}


int main(void)
{
    int array[] = {0,1,2,3,4};
    int *p;

    p = find_int(3, array, sizeof(array));
    printf("%d\n", *p);

    return EXIT_SUCCESS;
}
