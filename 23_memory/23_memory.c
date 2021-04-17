#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
C 语言为内存的分配和管理提供了几个函数。这些函数可以在 <stdlib.h> 头文件中找到。
1.void *calloc(int num, int size);
在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。所以它的结果是分配了 num*size 个字节长度的内存空间，
并且每个字节的值都是0。
2	void free(void *address); 
该函数释放 address 所指向的内存块,释放的是动态分配的内存空间。
3	void *malloc(int num); 
在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。
4	void *realloc(void *address, int newsize); 
该函数重新分配内存，把内存扩展到 newsize。

注意：void * 类型表示未确定类型的指针。C、C++ 规定 void * 类型可以通过类型转换强制转换为任何其它类型的指针。
*/

void test1()
{
    char name[100];
    char *text;

    strcpy(name, "Zhang San");

    // 动态分配内存
    // text = (char *)malloc(200 * sizeof(char));
    text = calloc(200, sizeof(char));
    if (NULL == text)
    {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else
    {
        strcpy(text, "this text is made of malloc");
    }

    printf("name = %s\n", name);
    printf("text = %s\n", text);
}

/*
当程序退出时，操作系统会自动释放所有分配给程序的内存，但是，建议在不需要内存时，都应该调用函数 free() 来释放内存。
或者，可以通过调用函数 realloc() 来增加或减少已分配的内存块的大小.
*/

void test2()
{
    char name[100];
    char *text;

    strcpy(name, "Zhang San");

    // 动态分配内存
    // text = (char *)malloc(200 * sizeof(char));
    text = calloc(200, sizeof(char));
    if (NULL == text)
    {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else
    {
        strcpy(text, "this text is made of malloc");
    }

    // 存储更多的信息
    text = (char *)realloc(text, 100 * sizeof(char));
    if (NULL == text)
    {
        fprintf(stderr, "Error - realloc is failed\n");
    }
    else
    {
        strcat(text, ", this is mede by realloc");
    }

    printf("name = %s\n", name);
    printf("text = %s\n", text);

    // 手动释放内存
    free(text);
}


/*
动态可变长的结构体：

typedef struct
{
  int id;
  char name[0];
}stu_t;
定义该结构体，只占用4字节的内存，name不占用内存。

stu_t *s = NULL;    //定义一个结构体指针
s = malloc(sizeof(*s) + 100);//sizeof(*s)获取的是4，但加上了100，4字节给id成员使用，100字节是属于name成员的
s->id = 1010;
strcpy(s->name,"hello");
注意：一个结构体中只能有一个可变长的成员，并且该成员必须是最后一个成员。
*/

void main()
{
    printf("test 1111111111111\n");
    // test1();

    printf("\ntest 2222222222222\n");
    test2();
}
