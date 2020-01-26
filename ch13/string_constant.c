#include <stdlib.h>
#include <stdio.h>

/* 根据参数值的一定比例打印相应数量的星号 */
void
mystery(int n)
{
    n += 5;
    n /= 10;
    printf("%s\n", "**********" + 10 - n);
}

void
binary_to_ascii(unsigned int value)
{
    unsigned int quotient;

    quotient = value / 10;
    if(quotient != 0)
        binary_to_ascii(quotient);
    putchar(value % 10 + '0');
}

int
main(void)
{
    puts("xyz" + 1); /* yz */
    printf("%c\n", *"xyz"); /* x */ 

    mystery(21);
    mystery(31);
    mystery(81);

    binary_to_ascii(789);
    putchar('\n');

    return EXIT_SUCCESS;
}
