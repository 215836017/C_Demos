#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef
/*
C 语言提供了 typedef 关键字，可以使用它来为类型取一个新的名字。下面的实例为单字节数字定义了一个术语 BYTE,
在这个类型定义之后，标识符 BYTE 可作为类型 unsigned char 的缩写。
按照惯例，定义时使用大写字母，以便提醒用户类型名称是一个象征性的缩写，但也可以使用小写字母。
*/
typedef unsigned char BYTE;

BYTE b1, b2;

/*
也可以使用 typedef 来为用户自定义的数据类型取一个新的名字。例如，您可以对结构体使用 typedef 来定义一个新的数据类型名字，然后使用这个新的数据类型来直接定义结构变量，
*/
typedef struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} Book;
void test1()
{
    Book book;
    strcpy(book.title, "C 教程");
    strcpy(book.author, "Runoob");
    strcpy(book.subject, "编程语言");
    book.book_id = 12345;

    printf("书标题 : %s\n", book.title);
    printf("书作者 : %s\n", book.author);
    printf("书类目 : %s\n", book.subject);
    printf("书 ID : %d\n", book.book_id);
}

/*
typedef vs #define
#define 是 C 指令，用于为各种数据类型定义别名，与 typedef 类似，但是它们有以下几点不同：

typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。
*/

#define TRUE 1
#define FALSE 0

void test2()
{
    printf("TRUE = %d \n", TRUE);
    printf("FALSE = %d \n", FALSE);
}

/*
#define可以使用其他类型说明符对宏类型名进行扩展，但对 typedef 所定义的类型名却不能这样做。例如：
#define INTERGE int;
unsigned INTERGE n;  //没问题
typedef int INTERGE;
unsigned INTERGE n;  //错误，不能在 INTERGE 前面添加 unsigned
*/

/*
在连续定义几个变量的时候，typedef 能够保证定义的所有变量均为同一类型，而 #define 则无法保证。例如：

#define PTR_INT int *
PTR_INT p1, p2;        //p1、p2 类型不相同，宏展开后变为int *p1, p2;
typedef int * PTR_INT
PTR_INT p1, p2;        //p1、p2 类型相同，它们都是指向 int 类型的指针。
*/

void main()
{

    printf("test 11111111111 \n");
    // test1();

    printf("\ntest 222222222222 \n");
    test2();
}
