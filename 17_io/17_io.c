#include <stdio.h>

void test1()
{

    char msg[100];
    printf("please input: \n");
    gets(msg);

    printf("\n your msg is :");
    puts(msg);
}

void test2()
{
    char msg[100];
    printf("please input: \n");
    fgets(msg, 100, stdin);

    printf("\n your msg is :");
    fputs(msg, stdout);
}

void main()
{

    printf("test 1111111111\n");
    // test1();

    printf("test 2222222222\n");
    test2();
}