#include <stdio.h>
#include <setjmp.h>

/*
setjmp.h 头文件定义了宏 setjmp()、函数 longjmp() 和变量类型 jmp_buf，该变量类型会绕过正常的函数调用和返回规则。

库变量
jmp_buf: 这是一个用于存储宏 setjmp() 和函数 longjmp() 相关信息的数组类型。
*/

/*
库宏
1	int setjmp(jmp_buf environment)
这个宏把当前环境保存在变量 environment 中，以便函数 longjmp() 后续使用。
如果这个宏直接从宏调用中返回，则它会返回零，但是如果它从 longjmp() 函数调用中返回，则它会返回一个非零值。
*/

/*
库函数
序号	函数 & 描述
1	void longjmp(jmp_buf environment, int value)
该函数恢复最近一次调用 setjmp() 宏时保存的环境，jmp_buf 参数的设置是由之前调用 setjmp() 生成的。
*/

static jmp_buf buf;

void second(void)
{
    printf("second\n"); // 打印
    longjmp(buf, 1);    // 跳回setjmp的调用处 - 使得setjmp返回值为1
}

void first(void)
{
    second();
    printf("first\n"); // 不可能执行到此行
}

void test1()
{
    if (!setjmp(buf))
    {
        first(); // 进入此行前，setjmp返回0
    }
    else
    {                     // 当longjmp跳转回，setjmp返回1，因此进入此行
        printf("main\n"); // 打印
    }
}

void main()
{

    printf("test 1111111111\n");
    test1();
}