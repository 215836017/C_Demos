#include <stdlib.h>

// 结构体

/*
C 数组允许定义可存储相同类型数据项的变量，结构是 C 编程中另一种用户自定义的可用的数据类型，它允许您存储不同类型的数据项
*/

/*
定义结构
为了定义结构，您必须使用 struct 语句。struct 语句定义了一个包含多个成员的新的数据类型，struct 语句的格式如下：

struct tag { 
    member-list
    member-list 
    member-list  
    ...
} variable-list ;
tag 是结构体标签。
member-list 是标准的变量定义，比如 int i; 或者 float f，或者其他有效的变量定义。
variable-list 结构变量，定义在结构的末尾，最后一个分号之前，您可以指定一个或多个结构变量。下面是声明 Book 结构的方式：

struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;

在一般情况下，tag、member-list、variable-list 这 3 部分至少要出现 2 个。以下为实例：
*/
//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
//同时又声明了结构体变量s1
//这个结构体并没有标明其标签
struct
{
    int a;
    char b;
    double c;
} s1;

//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
//结构体的标签被命名为SIMPLE,没有声明变量
struct SIMPLE
{
    int a;
    char b;
    double c;
};
//用SIMPLE标签的结构体，另外声明了变量t1、t2、t3
struct SIMPLE t1, t2[20], *t3;

//也可以用typedef创建新类型
typedef struct
{
    int a;
    char b;
    double c;
} Simple2;
//现在可以用Simple2作为类型声明新的结构体变量
Simple2 u1, u2[20], *u3;

/*
在上面的声明中，第一个和第二声明被编译器当作两个完全不同的类型，即使他们的成员列表是一样的，如果令 t3=&s1，则是非法的。
结构体的成员可以包含其他结构体，也可以包含指向自己结构体类型的指针，而通常这种指针的应用是为了实现一些更高级的数据结构如链表和树等。
*/

//此结构体的声明包含了其他的结构体
struct COMPLEX
{
    char string[100];
    struct SIMPLE a;
};

//此结构体的声明包含了指向自己类型的指针
struct NODE
{
    char string[100];
    struct NODE *next_node;
};

/*
如果两个结构体互相包含，则需要对其中一个结构体进行不完整声明，如下所示：
*/

struct B; //对结构体B进行不完整声明

//结构体A中包含指向结构体B的指针
struct A
{
    struct B *partner;
    //other members;
};

//结构体B中包含指向结构体A的指针，在A声明完后，B也随之进行声明
struct B
{
    struct A *partner;
    //other members;
};

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} book = {"C 语言", "RUNOOB", "编程语言", 123456};

void test1()
{
    printf("结构体变量的初始化: 和其它类型变量一样，对结构体变量可以在定义时指定初始值\n");
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);
}

void test2()
{
    // 为了访问结构的成员，使用成员访问运算符（.）。
    // 成员访问运算符是结构变量名称和我们要访问的结构成员之间的一个句号。可以使用 struct 关键字来定义结构类型的变量。

    struct Books Book1; /* 声明 Book1，类型为 Books */
    struct Books Book2; /* 声明 Book2，类型为 Books */

    /* Book1 详述 */
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Nuha Ali");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* Book2 详述 */
    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Zara Ali");
    strcpy(Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    /* 输出 Book1 信息 */
    printf("Book 1 title : %s\n", Book1.title);
    printf("Book 1 author : %s\n", Book1.author);
    printf("Book 1 subject : %s\n", Book1.subject);
    printf("Book 1 book_id : %d\n", Book1.book_id);

    /* 输出 Book2 信息 */
    printf("Book 2 title : %s\n", Book2.title);
    printf("Book 2 author : %s\n", Book2.author);
    printf("Book 2 subject : %s\n", Book2.subject);
    printf("Book 2 book_id : %d\n", Book2.book_id);
}

void printBook(struct Books book)
{
    printf("Book title : %s\n", book.title);
    printf("Book author : %s\n", book.author);
    printf("Book subject : %s\n", book.subject);
    printf("Book book_id : %d\n", book.book_id);
}
void test3()
{
    // 可以把结构作为函数参数，传参方式与其他类型的变量或指针类似。

    struct Books Book1; /* 声明 Book1，类型为 Books */
    struct Books Book2; /* 声明 Book2，类型为 Books */

    /* Book1 详述 */
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Nuha Ali");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* Book2 详述 */
    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Zara Ali");
    strcpy(Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    printf("打印book1\n");
    printBook(Book1);
    printf("\n打印book2\n");
    printBook(Book2);
}

void printBook2(struct Books *book)
{
    printf("Book title : %s\n", book->title);
    printf("Book author : %s\n", book->author);
    printf("Book subject : %s\n", book->subject);
    printf("Book book_id : %d\n", book->book_id);
}
void test4()
{

    struct Books Book1; /* 声明 Book1，类型为 Books */
    struct Books Book2; /* 声明 Book2，类型为 Books */

    /* Book1 详述 */
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Nuha Ali");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* Book2 详述 */
    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Zara Ali");
    strcpy(Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    // 可以定义指向结构的指针，方式与定义指向其他类型变量的指针相似
    struct Books *pBook1;

    // 可以在定义的指针变量中存储结构变量的地址。为了查找结构变量的地址，把 & 运算符放在结构名称的前面
    pBook1 = &Book1;

    /* 输出 Book1 信息 */
    printf("打印book1\n");
    printf("Book 1 title : %s\n", pBook1->title);
    printf("Book 1 author : %s\n", pBook1->author);
    printf("Book 1 subject : %s\n", pBook1->subject);
    printf("Book 1 book_id : %d\n", pBook1->book_id);

    /* 输出 Book1 信息 */
    printf("\n打印book2\n");
    printBook2(&Book2);
}

typedef struct
{
    unsigned char a;
    unsigned int b;
    unsigned char c;
} debug_size1_t;
typedef struct
{
    unsigned char a;
    unsigned char b;
    unsigned int c;
} debug_size2_t;
void test5()
{
    // 结构体的空间问题： 结构体中成员变量分配的空间是按照成员变量中占用空间最大的来作为分配单位,
    // 同样成员变量的存储空间也是不能跨分配单位的,如果当前的空间不足,则会存储到下一个分配单位中

    printf("debug_size1_t size=%lu,debug_size2_t size=%lu\r\n", sizeof(debug_size1_t), sizeof(debug_size2_t));
}

struct student
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
} stu[3] = {{10101, "AAA", 'M', 18, 87.5, "1011 Beijing Road"},
            {10102, "BBB", 'M', 19, 77.5, "1022 Beijing Road"},
            {10103, "CCC", 'M', 17, 67.5, "1033 Beijing Road"}};
void test6()
{
    // 结构体数组：可以在声明时初始化，也可以声明后再赋值。

    // student stu[3] = {{10101,"Li Lin", 'M', 18, 87.5, "103 Beijing Road"},
    //         {10101,"Li Lin", 'M', 18, 87.5, "103 Beijing Road"},
    //         {10101,"Li Lin", 'M', 18, 87.5, "103 Beijing Road"}};

    // 也可以数组内容明确时，元素个数可以不指定
    // student stu[] = {{10101,"Li Lin", 'M', 18, 87.5, "103 Beijing Road"},
    //         {10101,"Li Lin", 'M', 18, 87.5, "103 Beijing Road"},
    //         {10101,"Li Lin", 'M', 18, 87.5, "103 Beijing Road"}};

    int i;
    for (i = 0; i < 3; i++)
    {
        printf("第%d个学生：num = %d, name = %s, score = %f\n", i, stu[i].num, stu[i].name, stu[i].score);
    }
}

void main()
{
    printf("test 111111111\n");
    // test1();

    printf("\n\ntest 22222222222222\n");
    // test2();

    printf("\n\ntest 333333333333333\n");
    // test3();

    printf("\n\ntest 44444444444444\n");
    // test4();

    printf("\n\ntest 5555555555555555\n");
    // test5();

    printf("\n\ntest 5555555555555555\n");
    test6();
}
