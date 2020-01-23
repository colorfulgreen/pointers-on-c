#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* C 不具备布尔值类型，以整数代替。规则：
     * 零是假，任何非零值皆为真。
     */

    /* 如果一个变量包含一个任意的整型值，应该显式对它进行测试。 */
    int value = 0;
    if (value != 0) {
        printf("True\n");
    }

    /* 如果一个变量表示布尔值，应该始终把它设置为 0 或 1。然后像下面这样测试变量的值，而不和特定的值来比较。 */
    int cash_balance = 5;
    int positive_cash_flow = cash_balance >= 0;
    if ( positive_cash_flow ) {
        printf("Positive\n");
    }

    return 0;
}
