#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

/*
C 标准库的 errno.h 头文件定义了整数变量 errno，它是通过系统调用设置的，在错误事件中的某些库函数表明了什么发生了错误。
该宏扩展为 int 类型的可更改的左值，因此它可以被一个程序读取和修改。

在程序启动时，errno 设置为零，C 标准库中的特定函数修改它的值为一些非零值以表示某些类型的错误。
也可以在适当的时候修改它的值或重置为零。

errno.h 头文件定义了一系列表示不同错误代码的宏，这些宏应扩展为类型为 int 的整数常量表达式。
*/

/*
下面列出了头文件 errno.h 中定义的宏：
1	extern int errno
这是通过系统调用设置的宏，在错误事件中的某些库函数表明了什么发生了错误。
2	EDOM Domain Error
这个宏表示一个域错误，它在输入参数超出数学函数定义的域时发生，errno 被设置为 EDOM。
3	ERANGE Range Error
这个宏表示一个范围错误，它在输入参数超出数学函数定义的范围时发生，errno 被设置为 ERANGE。
*/

extern int errno;

void test1()
{
    FILE *fp = NULL;
    fp = fopen("test.txt", "r"); // test.txt not exist
    if (NULL == fp)
    {
        fprintf(stderr, "value of error = %d \n", errno);
        fprintf(stderr, "error msg = %s\n", strerror(errno));
    }
    else
    {
        fclose(fp);
    }
}

void test2()
{
    double val;

    errno = 0;
    val = sqrt(-10); // Linux下编译：gcc -o main 21_error_1.c -lm
    if (errno == EDOM)
    {
        printf("errno = %d, Invalid value \n", errno);
    }
    else
    {
        printf("Valid value\n");
    }

    errno = 0;
    val = sqrt(10);
    if (errno == EDOM)
    {
        printf("Invalid value\n");
    }
    else
    {
        printf("Valid value\n");
    }
}

void test3()
{
    double x;
    double value;

    x = 2.000000;
    value = log(x);

    if (errno == ERANGE)
    {
        printf("Log(%f) is out of range\n", x);
    }
    else
    {
        printf("Log(%f) = %f\n", x, value);
    }

    x = 1.000000;
    value = log(x);

    if (errno == ERANGE)
    {
        printf("Log(%f) is out of range\n", x);
    }
    else
    {
        printf("Log(%f) = %f\n", x, value);
    }

    x = 0.000000;
    value = log(x);

    if (errno == ERANGE)
    {
        printf("Log(%f) is out of range\n", x);
    }
    else
    {
        printf("Log(%f) = %f\n", x, value);
    }
}
void main()
{

    printf("test 111111111111\n");
    // test1();

    printf("\ntest 222222222222\n");
    // test2();

    printf("\ntest 33333333333333\n");
    test3();
}