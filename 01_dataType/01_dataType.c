#include <stdio.h>
#include <float.h>


    // 标题：数据类型

void main(){
	
	

	printf("Hello World!\n");

	/*
	C 中的类型可分为以下几种：
	1	基本类型：它们是算术类型，包括两种类型：整数类型和浮点类型。
	2	枚举类型：它们也是算术类型，被用来定义在程序中只能赋予其一定的离散整数值的变量。
	3	void 类型：类型说明符 void 表明没有可用的值。
	4	派生类型：它们包括：指针类型、数组类型、结构类型、共用体类型和函数类型。
	*/

	/*
	整数类型,下表列出了关于标准整数类型的存储大小和值范围的细节：

类型	存储大小	值范围
char	1 字节	-128 到 127 或 0 到 255
unsigned char	1 字节	0 到 255
signed char	1 字节	-128 到 127
int	2 或 4 字节	-32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647
unsigned int	2 或 4 字节	0 到 65,535 或 0 到 4,294,967,295
short	2 字节	-32,768 到 32,767
unsigned short	2 字节	0 到 65,535
long	4 字节	-2,147,483,648 到 2,147,483,647
unsigned long	4 字节	0 到 4,294,967,295
	*/

	/*
	浮点类型,下表列出了关于标准浮点类型的存储大小、值范围和精度的细节：

类型	存储大小	值范围	精度
float	4 字节	1.2E-38 到 3.4E+38	6 位小数
double	8 字节	2.3E-308 到 1.7E+308	15 位小数
long double	16 字节	3.4E-4932 到 1.1E+4932	19 位小数
	*/

	
	/*
	void 类型指定没有可用的值。它通常用于以下三种情况下：
	1	函数返回为空: C 中有各种函数都不返回值，或者您可以说它们返回空。不返回值的函数的返回类型为空。例如 void exit (int status);
	2	函数参数为空: C 中有各种函数不接受任何参数。不带参数的函数可以接受一个 void。例如 int rand(void);
	3	指针指向 void: 类型为 void * 的指针代表对象的地址，而不是类型。例如，内存分配函数 void *malloc( size_t size ); 返回指向 void 的指针，可以转换为任何数据类型。
	*/

//  函数sizeof
	printf("int 的存储大小： %lu \n", sizeof(int));
	printf("float 的存储大小： %lu \n", sizeof(float));

//  头文件 float.h 定义了宏，在程序中可以使用这些值和其他有关实数二进制表示的细节。
   printf("float 最小值: %E\n", FLT_MIN );
   printf("float 最大值: %E\n", FLT_MAX );
   printf("精度值: %d\n", FLT_DIG );

}