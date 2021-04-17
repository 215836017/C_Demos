#include <stdio.h>
#include <math.h>

/*
math.h 头文件定义了各种数学函数和一个宏。在这个库中所有可用的功能都带有一个 double 类型的参数，且都返回 double 类型的结果。
*/

/*
库宏
下面是这个库中定义的唯一的一个宏：

HUGE_VAL
当函数的结果不可以表示为浮点数时。如果是因为结果的幅度太大以致于无法表示，则函数会设置 errno 为 ERANGE 来表示范围错误，
并返回一个由宏 HUGE_VAL 或者它的否定（- HUGE_VAL）命名的一个特定的很大的值。
如果结果的幅度太小，则会返回零值。在这种情况下，error 可能会被设置为 ERANGE，也有可能不会被设置为 ERANGE。
*/

/*
库函数
下面列出了头文件 math.h 中定义的函数：

序号	函数 & 描述
1	double acos(double x)
返回以弧度表示的 x 的反余弦。
2	double asin(double x)
返回以弧度表示的 x 的反正弦。
3	double atan(double x)
返回以弧度表示的 x 的反正切。
4	double atan2(double y, double x)
返回以弧度表示的 y/x 的反正切。y 和 x 的值的符号决定了正确的象限。
5	double cos(double x)
返回弧度角 x 的余弦。
6	double cosh(double x)
返回 x 的双曲余弦。
7	double sin(double x)
返回弧度角 x 的正弦。
8	double sinh(double x)
返回 x 的双曲正弦。
9	double tanh(double x)
返回 x 的双曲正切。
10	double exp(double x)
返回 e 的 x 次幂的值。
11	double frexp(double x, int *exponent)
把浮点数 x 分解成尾数和指数。返回值是尾数，并将指数存入 exponent 中。所得的值是 x = mantissa * 2 ^ exponent。
12	double ldexp(double x, int exponent)
返回 x 乘以 2 的 exponent 次幂。
13	double log(double x)
返回 x 的自然对数（基数为 e 的对数）。
14	double log10(double x)
返回 x 的常用对数（基数为 10 的对数）。
15	double modf(double x, double *integer)
返回值为小数部分（小数点后的部分），并设置 integer 为整数部分。
16	double pow(double x, double y)
返回 x 的 y 次幂。
17	double sqrt(double x)
返回 x 的平方根。
18	double ceil(double x)
返回大于或等于 x 的最小的整数值。
19	double fabs(double x)
返回 x 的绝对值。
20	double floor(double x)
返回小于或等于 x 的最大的整数值。
21	double fmod(double x, double y)
返回 x 除以 y 的余数。
*/

#define PI 3.14159265
void test1()
{
    double x, ret, val;

    x = 0.9;
    val = 180.0 / PI;

    ret = acos(x) * val;
    printf("%lf 的反余弦是 %lf 度\n", x, ret);
}

void test2()
{
    double x = 0;

    printf("e 的 %lf 次幂是 %lf\n", x, exp(x));
    printf("e 的 %lf 次幂是 %lf\n", x + 1, exp(x + 1));
    printf("e 的 %lf 次幂是 %lf\n", x + 2, exp(x + 2));
}

void test3()
{
    float val1, val2, val3, val4;

    val1 = 1.6;
    val2 = 1.2;
    val3 = 2.8;
    val4 = 2.3;

    printf("value1 = %.1lf\n", ceil(val1));
    printf("value2 = %.1lf\n", ceil(val2));
    printf("value3 = %.1lf\n", ceil(val3));
    printf("value4 = %.1lf\n", ceil(val4));
}
void main()
{

    // Linux下编译需使用命令： ggc -o main xxx.c -lm
    printf("test 1111111111\n");
    test1();

    printf("\ntest 22222222222\n");
    test2();

    printf("\ntest 333333333333\n");
    test3();
}