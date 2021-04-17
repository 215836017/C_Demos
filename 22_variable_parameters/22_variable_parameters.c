#include <stdio.h>
#include <stdarg.h>

/*
有时，可能会碰到这样的情况，希望函数带有可变数量的参数，而不是预定义数量的参数。
C 语言为这种情况提供了一个解决方案，它允许定义一个函数，能根据具体的需求接受可变数量的参数.
int func(int, ... ) 
{
   ...
}
 
int main()
{
   func(2, 2, 3);
   func(3, 2, 3, 4);
}

注意，函数 func() 最后一个参数写成省略号，即三个点号（...），

---------- 很重要：省略号之前的那个参数是 int，代表了要传递的可变参数的总数。-----------

为了使用这个功能，需要使用 stdarg.h 头文件，该文件提供了实现可变参数功能的函数和宏。具体步骤如下：
定义一个函数，最后一个参数为省略号，省略号前面可以设置自定义参数。
在函数定义中创建一个 va_list 类型变量，该类型是在 stdarg.h 头文件中定义的。
使用 int 参数和 va_start 宏来初始化 va_list 变量为一个参数列表。宏 va_start 是在 stdarg.h 头文件中定义的。
使用 va_arg 宏和 va_list 变量来访问参数列表中的每个项。
使用宏 va_end 来清理赋予 va_list 变量的内存。

*/

double test1(int num, ...)
{
    va_list valist;
    double sum = 0.0;
    int i;

    /* 为 num 个参数初始化 valist */
    va_start(valist, num);

    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);

    return sum / num;
}

void main()
{

    printf("test 111111111111111\n");
    printf("Average of 2, 3, 4, 5 = %f\n", test1(4, 2, 3, 4, 5));
    printf("Average of 5, 10, 15 = %f\n", test1(3, 5, 10, 15));
}