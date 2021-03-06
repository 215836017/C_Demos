#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
C 语言不提供对错误处理的直接支持，但是作为一种系统编程语言，它以返回值的形式允许访问底层数据。在发生错误时，
大多数的 C 或 UNIX 函数调用返回 1 或 NULL，同时会设置一个错误代码 errno，该错误代码是全局变量，表示在函数调用期间发生了错误。
可以在 errno.h 头文件中找到各种各样的错误代码。
所以，C 程序员可以通过检查返回值，然后根据返回值决定采取哪种适当的动作。开发人员应该在程序初始化时，把 errno 设置为 0，
这是一种良好的编程习惯。0 值表示程序中没有错误。
*/

/*
errno、perror() 和 strerror()
C 语言提供了 perror() 和 strerror() 函数来显示与 errno 相关的文本消息。

perror() 函数显示传给它的字符串，后跟一个冒号、一个空格和当前 errno 值的文本表示形式。
strerror() 函数，返回一个指针，指针指向当前 errno 值的文本表示形式。

让我们来模拟一种错误情况，尝试打开一个不存在的文件。可以使用多种方式来输出错误消息，在这里我们使用函数来演示用法。
另外有一点需要注意，应该使用 stderr 文件流来输出所有的错误。
*/

extern int errno;
void test1()
{
    FILE *pf;
    int errnum;
    pf = fopen("unexist.txt", "rb");
    if (pf == NULL)
    {
        printf("error 111\n");
        errnum = errno;
        fprintf(stderr, "错误号: %d\n", errno);

        printf("\n\nerror 222\n");
        perror("通过 perror 输出错误");

        printf("\n\nerror 333 \n");
        fprintf(stderr, "打开文件错误: %s\n", strerror(errnum));
    }
    else
    {
        fclose(pf);
    }
}

void main()
{
    printf("test 1111111111111\n");
    test1();
}