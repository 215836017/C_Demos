#include <stdio.h>
#include <string.h>

/*
共用体是一种特殊的数据类型，允许在相同的内存位置存储不同的数据类型。
可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值。
共用体提供了一种使用相同的内存位置的有效方式。
*/

/*
定义共用体使用 union 语句，方式与定义结构类似。union 语句定义了一个新的数据类型，带有多个成员
*/
union Data
{
    int age;
    float score;
    char name[20];
};
/*
现在，Data 类型的变量可以存储一个整数、一个浮点数，或者一个字符串。
这意味着一个变量（相同的内存位置）可以存储多个多种类型的数据。可以根据需要在一个共用体内使用任何内置的或者用户自定义的数据类型。

共用体占用的内存应足够存储共用体中最大的成员。在Data中将占用20个字节的内存空间，因为在各个成员中，字符串所占用的空间是最大的。
*/

void test1()
{
    union Data data;
    printf("Memory size of data is : %ld\n", sizeof(data));
}

/*
使用成员访问运算符（.）访问共用体的成员。成员访问运算符是共用体变量名称和我们要访问的共用体成员之间的一个英文句号。
*/
void test2()
{
    union Data data;
    data.age = 10;
    data.score = 11.11;
    strcpy(data.name, "abcdef");

    printf("data.age = %d\n", data.age);
    printf("data.score = %f\n", data.score);
    printf("data.name = %s\n", data.name);
}
/*
运行结果:
data.age = 1684234849
data.score = 16777999408082104352768.000000
data.name = abcdef

在这里，我们可以看到共用体的 i 和 f 成员的值有损坏，因为最后赋给变量的值占用了内存位置，这也是 str 成员能够完好输出的原因。现在让我们再来看一个相同的实例，这次我们在同一时间只使用一个变量
*/

void test3()
{
    union Data data;

    data.age = 10;
    printf("data.age = %d\n", data.age);

    data.score = 11.11;
    printf("data.score = %f\n", data.score);

    strcpy(data.name, "abcdef");
    printf("data.name = %s\n", data.name);
}
/*
运行结果:
data.age = 10
data.score = 11.110000
data.name = abcdef
*/
int main()
{

    printf("test 1111111111111 \n");
    // test1();

    printf("\ntest 22222222222 \n");
    test2();

    printf("\ntest 333333333333 \n");
    test3();
    return 0;
}