#include <stdlib.h>
#include <stdio.h>

double my_add(double, double);
double my_sub(double, double);
double my_mul(double, double);
double my_div(double, double);

/* 声明并初始化一个函数指针数组。
 * 需确保函数原型出现在数组声明之前。
 */
double (*oper_func[])(double, double) = {
    my_add, my_sub, my_mul, my_div
};

double my_add(double x, double y)
{
    return x + y;
}

double my_sub(double x, double y)
{
    return x - y;
}

double my_mul(double x, double y)
{
    return x * y;
}

double my_div(double x, double y)
{
    return x / y;
}

int main( void )
{
    double result;
    result = oper_func[1](3.1, 2);
    printf("%f\n", result);
    return EXIT_SUCCESS;
}
