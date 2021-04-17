
#include <stdio.h>
#include <assert.h>

/*
C 标准库的 assert.h头文件提供了一个名为 assert 的宏，它可用于验证程序做出的假设，并在假设为假时输出诊断消息。
已定义的宏 assert 指向另一个宏 NDEBUG，宏 NDEBUG 不是 <assert.h> 的一部分。
如果已在引用 <assert.h> 的源文件中定义 NDEBUG 为宏名称，则 assert 宏的定义如下：
#define assert(ignore) ((void)0)
*/

/*
void assert(int expression)
这实际上是一个宏，不是一个函数，可用于在 C 程序中添加诊断。

ASSERT() 是一个调试程序时经常使用的宏，在程序运行时它计算括号内的表达式，如果表达式为 FALSE (0), 程序将报告错误，并终止执行。
如果表达式不为 0，则继续执行后面的语句。

这个宏通常原来判断程序中是否出现了明显非法的数据，如果出现了终止程序以免导致严重后果，同时也便于查找错误。
ASSERT 只有在 Debug 版本中才有效，如果编译为 Release 版本则被忽略
*/

void main()
{
    printf("test assert() 111\n");
    int a = 1;
    assert(a);

    printf("test assert() 222222\n");
    int b = 0;
    assert(a);

    printf("test assert() 33333\n");
}