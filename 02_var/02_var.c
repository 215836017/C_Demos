#include<stdio.h>


  /*
    不带初始化的定义：带有静态存储持续时间的变量会被隐式初始化为 NULL（所有字节的值都是 0），其他所有变量的初始值是未定义的。
  */
    
    /*
    C 中的变量声明
变量声明向编译器保证变量以指定的类型和名称存在，这样编译器在不需要知道变量完整细节的情况下也能继续进一步的编译。变量声明只在编译时
有它的意义，在程序连接时编译器需要实际的变量声明。变量的声明有两种情况：

1、一种是需要建立存储空间的。例如：int a 在声明的时候就已经建立了存储空间。
2、另一种是不需要建立存储空间的，通过使用extern关键字声明变量名而不定义它。 例如：extern int a 其中变量 a 可以在别的文件中定义的。
除非有extern关键字，否则都是变量的定义。
    */


int x, y;
int testX = 123;
int testY = 456;
int addFun();

int funAdd(){
	x = 100;
	y = 200;

	return x + y;
}


int main(){

    extern int a, b;    // a 和 b 的声明
    int d = 3, f = 5;           // 定义并初始化 d 和 f
    char c = 'x';               // 变量 c 的值为 'x'

    int resultOfAdd;
    int resultOfAdd2;

    resultOfAdd = funAdd();

    printf("resultOfAdd = %d\n", resultOfAdd);

    resultOfAdd2 = addFun();  
    //编译02_var.c和02_test_add.c 的语法：gcc 02_test_add.c 02_var.c -o testAdd(testAdd可以随便起名)
    printf("resultOfAdd2 = %d\n", resultOfAdd2);
}