

#include <stdio.h>

/*
C 预处理器不是编译器的组成部分，但是它是编译过程中一个单独的步骤。简言之，C 预处理器只不过是一个文本替换工具而已，
它们会指示编译器在实际编译之前完成所需的预处理。我们将把 C 预处理器（C Preprocessor）简写为 CPP。

所有的预处理器命令都是以井号（#）开头。它必须是第一个非空字符，为了增强可读性，预处理器指令应从第一列开始。
下面列出了所有重要的预处理器指令：
#define	定义宏
#include	包含一个源代码文件
#undef	取消已定义的宏
#ifdef	如果宏已经定义，则返回真
#ifndef	如果宏没有定义，则返回真
#if	如果给定条件为真，则编译下面代码
#else	#if 的替代方案
#elif	如果前面的 #if 给定条件不为真，当前条件为真，则编译下面代码
#endif	结束一个 #if……#else 条件编译块
#error	当遇到标准错误时，输出错误消息
#pragma	使用标准化方法，向编译器发布特殊的命令到编译器中
*/

#undef FILE_SIZE
#define FILE_SIZE 42
// 取消已定义的 FILE_SIZE，并定义它为 42。

#ifndef MESSAGE
#define MESSAGE "You wish!"
#endif
// 这个指令告诉 CPP 只有当 MESSAGE 未定义时，才定义 MESSAGE。

#ifdef DEBUG
/* Your debugging statements here */
#endif
// 这个指令告诉 CPP 如果定义了 DEBUG，则执行处理语句。
// 在编译时，如果您向 gcc 编译器传递了 -DDEBUG 开关量，这个指令就非常有用。它定义了 DEBUG，您可以在编译期间随时开启或关闭调试。

void test1()
{
    printf("File :%s\n", __FILE__);
    printf("Date :%s\n", __DATE__);
    printf("Time :%s\n", __TIME__);
    printf("Line :%d\n", __LINE__);
    printf("ANSI :%d\n", __STDC__);
}

/*
C 预处理器提供了下列的运算符来创建宏：

宏延续运算符（\）
一个宏通常写在一个单行上。但是如果宏太长，一个单行容纳不下，则使用宏延续运算符（\）。例如：
#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")

字符串常量化运算符（#）
在宏定义中，当需要把一个宏的参数转换为字符串常量时，则使用字符串常量化运算符（#）。在宏中使用的该运算符有一个特定的参数或参数列表。
例如：
#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")
*/

#define message_for(a, b) \
    printf(#a " and " #b ": We love you!\n")

void test2()
{
    message_for(Carole, Debra);
}

/*
标记粘贴运算符（##）
宏定义内的标记粘贴运算符（##）会合并两个参数。它允许在宏定义中两个独立的标记被合并为一个标记。
*/
#define tokenpaster(n) printf("token" #n " = %d", token##n)
void test3()
{
    int token34 = 40;

    tokenpaster(34);
}

/*
defined() 运算符
预处理器 defined 运算符是用在常量表达式中的，用来确定一个标识符是否已经使用 #define 定义过。
如果指定的标识符已定义，则值为真（非零）。如果指定的标识符未定义，则值为假（零）。
*/
#if !defined(MESSAGE)
#define MESSAGE "You wish!"
#endif

voidtest4()
{
    printf("Here is the message: %s\n", MESSAGE);
}

/*
参数化的宏
CPP 一个强大的功能是可以使用参数化的宏来模拟函数。例如，下面的代码是计算一个数的平方,可以使用宏重写上面的代码
在使用带有参数的宏之前，必须使用 #define 指令定义。
参数列表是括在圆括号内，且必须紧跟在宏名称的后边。宏名称和左圆括号之间不允许有空格
*/

int square(int x)
{
    return x * x;
}
#define square1(x) ((x) * (x)) //使用宏重写上面的代码

void test5()
{

    printf("square = %d \n", square(4));
    printf("square1 = %d \n", square1(4));
}

void main()
{

    printf("test 111111111111111\n");
    // test1();

    printf("\ntest 2222222222222\n");
    // test2();

    printf("\ntest 3333333333333\n");
    // test3();

    printf("\ntest 4444444444444\n");
    // test4();

    printf("\ntest 55555555555\n");
    test5();
}