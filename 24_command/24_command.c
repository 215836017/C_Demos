#include <stdio.h>

/*
执行程序时，可以从命令行传值给 C 程序。这些值被称为命令行参数，它们对程序很重要，特别是想从外部控制程序，
而不是在代码内对这些值进行硬编码时，就显得尤为重要了。
命令行参数是使用 main() 函数参数来处理的，其中:
argc 是指传入参数的个数，
argv[] 是一个指针数组，指向传递给程序的每个参数。
*/

void main1(int argc, char *argv[])
{

    if (argc == 2)
    {
        printf("The argument supplied is %s\n", argv[1]);
    }
    else if (argc > 2)
    {
        printf("too many arguments \n");
    }
    else
    {
        printf("one argument\n");
    }
}

/*
应当指出的是，argv[0] 存储程序的名称，argv[1] 是一个指向第一个命令行参数的指针，*argv[n] 是最后一个参数。
如果没有提供任何参数，argc 将为 1，否则，如果传递了一个参数，argc 将被设置为 2。
多个命令行参数之间用空格分隔，但是如果参数本身带有空格，那么传递参数的时候应把参数放置在双引号 "" 或单引号 '' 内部。
*/

void main(int argc, char *argv[])
{
    printf("Program name %s\n", argv[0]);

    if (argc == 2)
    {
        printf("The argument supplied is %s\n", argv[1]);
    }
    else if (argc > 2)
    {
        printf("Too many arguments supplied.\n");
    }
    else
    {
        printf("One argument expected.\n");
    }
}