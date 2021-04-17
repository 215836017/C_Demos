#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

/*
signal.h 头文件定义了一个变量类型 sig_atomic_t、两个函数调用和一些宏来处理程序执行期间报告的不同信号。
*/

/*
库变量
sig_atomic_t : 这是 int 类型，在信号处理程序中作为变量使用。它是一个对象的整数类型，该对象可以作为一个原子实体访问，
即使存在异步信号时，该对象可以作为一个原子实体访问。
*/

/*
库宏
下面是头文件 signal.h 中定义的宏，这些宏将在下列两个函数中使用。SIG_ 宏与 signal 函数一起使用来定义信号的功能。

序号	宏 & 描述
1	SIG_DFL
默认的信号处理程序。
2	SIG_ERR
表示一个信号错误。
3	SIG_IGN
忽视信号。

SIG 宏用于表示以下各种条件的信号码：
序号	宏 & 描述
1	SIGABRT
程序异常终止。
2	SIGFPE
算术运算出错，如除数为 0 或溢出。
3	SIGILL
非法函数映象，如非法指令。
4	SIGINT
中断信号，如 ctrl-C。
5	SIGSEGV
非法访问存储器，如访问不存在的内存单元。
6	SIGTERM
发送给本程序的终止请求信号。
*/

/*
库函数
下面是头文件 signal.h 中定义的函数：

序号	函数 & 描述
1	void (*signal(int sig, void (*func)(int)))(int)
该函数设置一个函数来处理信号，即信号处理程序。
2	int raise(int sig)
该函数会促使生成信号 sig。sig 参数与 SIG 宏兼容。
*/

/*
 对于signal() 函数：
void (*signal(int sig, void (*func)(int)))(int)
参数：
sig -- 在信号处理程序中作为变量使用的信号码。下面是一些重要的标准信号常量：
宏	信号
SIGABRT	(Signal Abort) 程序异常终止。
SIGFPE	(Signal Floating-Point Exception) 算术运算出错，如除数为 0 或溢出（不一定是浮点运算）。
SIGILL	(Signal Illegal Instruction) 非法函数映象，如非法指令，通常是由于代码中的某个变体或者尝试执行数据导致的。
SIGINT	(Signal Interrupt) 中断信号，如 ctrl-C，通常由用户生成。
SIGSEGV	(Signal Segmentation Violation) 非法访问存储器，如访问不存在的内存单元。
SIGTERM	(Signal Terminate) 发送给本程序的终止请求信号。
func -- 一个指向函数的指针。它可以是一个由程序定义的函数，也可以是下面预定义函数之一：
SIG_DFL	默认的信号处理程序。
SIG_IGN	忽视信号。

返回值
该函数返回信号处理程序之前的值，当发生错误时返回 SIG_ERR。
*/

void sighandler(int signum)
{
    printf("捕获信号 %d，跳出...\n", signum); // 程序运行后会进入无限循环，需使用 CTRL + C 键跳出程序
    exit(1);
}
void test1()
{
    signal(SIGINT, sighandler);

    while (1)
    {
        printf("开始休眠一秒钟...\n");
        sleep(1);
    }
}

/*
对于函数：int raise(int sig)
参数
sig -- 要发送的信号码。下面是一些重要的标准信号常量：
宏	信号
SIGABRT	(Signal Abort) 程序异常终止。
SIGFPE	(Signal Floating-Point Exception) 算术运算出错，如除数为 0 或溢出（不一定是浮点运算）。
SIGILL	(Signal Illegal Instruction) 非法函数映象，如非法指令，通常是由于代码中的某个变体或者尝试执行数据导致的。
SIGINT	(Signal Interrupt) 中断信号，如 ctrl-C，通常由用户生成。
SIGSEGV	(Signal Segmentation Violation) 非法访问存储器，如访问不存在的内存单元。
SIGTERM	(Signal Terminate) 发送给本程序的终止请求信号。
返回值
如果成功该函数返回零，否则返回非零。
*/
void signal_catchfunc(int signal)
{
    printf("!! 信号捕获 !!\n");
}

void test2()
{
    int ret;

    ret = signal(SIGINT, signal_catchfunc);

    if (ret == SIG_ERR)
    {
        printf("错误：不能设置信号处理程序。\n");
        exit(0);
    }
    printf("开始生成一个信号\n");
    ret = raise(SIGINT);
    if (ret != 0)
    {
        printf("错误：不能生成 SIGINT 信号。\n");
        exit(0);
    }

    printf("退出...\n");
}
void main()
{
    printf("test 111111111111\n");
    // test1();

    printf("\ntest 22222222222\n");
    test2();
}