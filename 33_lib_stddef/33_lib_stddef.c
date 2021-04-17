#include <stdio.h>
#include <stddef.h>

/*
stddef.h 头文件定义了各种变量类型和宏。这些定义中的大部分也出现在其它头文件中。
*/

/*
库变量
下面是头文件 stddef.h 中定义的变量类型：

序号	变量 & 描述
1	ptrdiff_t
这是有符号整数类型，它是两个指针相减的结果。
2	size_t 
这是无符号整数类型，它是 sizeof 关键字的结果。
3	wchar_t 
这是一个宽字符常量大小的整数类型。
*/

/*
库宏
下面是头文件 stddef.h 中定义的宏：

序号	宏 & 描述
1	NULL
这个宏是一个空指针常量的值。
2	offsetof(type, member-designator)
这会生成一个类型为 size_t 的整型常量，它是一个结构成员相对于结构开头的字节偏移量。
成员是由 member-designator 给定的，结构的名称是在 type 中给定的。
*/

void test1()
{
    FILE *fp;

    fp = fopen("file.txt", "r");
    if (fp != NULL)
    {
        printf("成功打开文件 file.txt\n");
        fclose(fp);
    }

    fp = fopen("nofile.txt", "r");
    if (fp == NULL)
    {
        printf("不能打开文件 nofile.txt\n");
    }
}

/*
offsetof() 宏的声明。
offsetof(type, member-designator)
参数
type -- 这是一个 class 类型，其中，member-designator 是一个有效的成员指示器。
member-designator -- 这是一个 class 类型的成员指示器。
返回值
该宏返回类型为 size_t 的值，表示 type 中成员的偏移量。
*/

struct address
{
    char name[50];
    char street[50];
    int phone;
};
void test2()
{
    printf("address 结构中的 name 偏移 = %d 字节。\n",
           offsetof(struct address, name));

    printf("address 结构中的 street 偏移 = %d 字节。\n",
           offsetof(struct address, street));

    printf("address 结构中的 phone 偏移 = %d 字节。\n",
           offsetof(struct address, phone));
}

void main()
{
    printf("test 111111111111\n");
    test1();

    printf("\ntest 2222222222\n");
    test2();
}