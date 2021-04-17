#include <stdio.h>
#include <ctype.h>
/*
C 标准库的 ctype.h 头文件提供了一些函数，可用于测试和映射字符。这些函数接受 int 作为参数，它的值必须是 EOF 或表示为一个无符号字符。
如果参数 c 满足描述的条件，则这些函数返回非零（true）。如果参数 c 不满足描述的条件，则这些函数返回零。
*/

/*
1   int isalnum(int c)
该函数检查所传的字符是否是字母和数字。
2	int isalpha(int c)
该函数检查所传的字符是否是字母。
3	int iscntrl(int c)
该函数检查所传的字符是否是控制字符。
4	int isdigit(int c)
该函数检查所传的字符是否是十进制数字。
5	int isgraph(int c)
该函数检查所传的字符是否有图形表示法。
6	int islower(int c)
该函数检查所传的字符是否是小写字母。
7	int isprint(int c)
该函数检查所传的字符是否是可打印的。
8	int ispunct(int c)
该函数检查所传的字符是否是标点符号字符。
9	int isspace(int c)
该函数检查所传的字符是否是空白字符。
10	int isupper(int c)
该函数检查所传的字符是否是大写字母。
11	int isxdigit(int c)
该函数检查所传的字符是否是十六进制数字。

标准库还包含了两个转换函数，它们接受并返回一个 "int"
1	int tolower(int c)
该函数把大写字母转换为小写字母。
2	int toupper(int c)
该函数把小写字母转换为大写字母。
*/

void test1()
{
    int var1 = 'd';
    int var2 = '2';
    int var3 = '\t';
    int var4 = ' ';

    if (isalnum(var1))
    {
        printf("var1 = |%c| 是字母数字\n", var1);
    }
    else
    {
        printf("var1 = |%c| 不是字母数字\n", var1);
    }

    if (isalnum(var2))
    {
        printf("var2 = |%c| 是字母数字\n", var2);
    }
    else
    {
        printf("var2 = |%c| 不是字母数字\n", var2);
    }

    if (isalnum(var3))
    {
        printf("var3 = |%c| 是字母数字\n", var3);
    }
    else
    {
        printf("var3 = |%c| 不是字母数字\n", var3);
    }

    if (isalnum(var4))
    {
        printf("var4 = |%c| 是字母数字\n", var4);
    }
    else
    {
        printf("var4 = |%c| 不是字母数字\n", var4);
    }
}

void test2()
{
    int var1 = 'd';
    int var2 = '2';
    int var3 = '\t';
    int var4 = ' ';

    if (isalpha(var1))
    {
        printf("var1 = |%c| 是一个字母\n", var1);
    }
    else
    {
        printf("var1 = |%c| 不是一个字母\n", var1);
    }

    if (isalpha(var2))
    {
        printf("var2 = |%c| 是一个字母\n", var2);
    }
    else
    {
        printf("var2 = |%c| 不是一个字母\n", var2);
    }

    if (isalpha(var3))
    {
        printf("var3 = |%c| 是一个字母\n", var3);
    }
    else
    {
        printf("var3 = |%c| 不是一个字母\n", var3);
    }

    if (isalpha(var4))
    {
        printf("var4 = |%c| 是一个字母\n", var4);
    }
    else
    {
        printf("var4 = |%c| 不是一个字母\n", var4);
    }
}

void test3()
{
    int i = 0, j = 0;
    char str1[] = "all \a about \t programming";
    char str2[] = "Runoob \n tutorials";

    /* 输出字符串直到控制字符 \a */
    while (!iscntrl(str1[i]))
    {
        putchar(str1[i]);
        i++;
    }

    /* 输出字符串直到控制字符 \n */
    while (!iscntrl(str2[j]))
    {
        putchar(str2[j]);
        j++;
    }
    printf("\n");
}
void main()
{
    printf("test 111111111111\n");
    // test1();

    printf("\ntest 2222222222\n");
    // test2();

    printf("\ntest 333333333\n");
    test3();
}