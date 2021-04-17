#include <stdio.h>

// 位域

/*
有些信息在存储时，并不需要占用一个完整的字节，而只需占几个或一个二进制位。例如在存放一个开关量时，只有 0 和 1 两种状态，
用 1 位二进位即可。为了节省存储空间，并使处理简便，C 语言又提供了一种数据结构，称为"位域"或"位段"。

所谓"位域"是把一个字节中的二进位划分为几个不同的区域，并说明每个区域的位数。
每个域有一个域名，允许在程序中按域名进行操作。这样就可以把几个不同的对象用一个字节的二进制位域来表示。

典型的实例：
用 1 位二进位存放一个开关量时，只有 0 和 1 两种状态。
读取外部文件格式——可以读取非标准的文件格式。例如：9 位的整数
*/

/*
如果程序的结构中包含多个开关量，只有 TRUE/FALSE 变量，如下：
*/
struct
{
    unsigned int widthValidated;
    unsigned int heightValidated;
} status;

/*
这种结构需要 8 字节的内存空间，但在实际上，在每个变量中，我们只存储 0 或 1。
在这种情况下，C 语言提供了一种更好的利用内存空间的方式。如果在结构内使用这样的变量，可以定义变量的宽度来告诉编译器，
将只使用这些字节。例如，上面的结构可以重写成：
*/
struct
{
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;
} status1;
/*
现在，在结构status1中 变量将占用 4 个字节的内存空间，但是只有 2 位被用来存储值。
如果用了 32 个变量，每一个变量宽度为 1 位，那么 status1 结构将使用 4 个字节，
但只要再多用一个变量，如果使用了33个变量，那么它将分配内存的下一段来存储第 33 个变量，这个时候就开始使用 8 个字节。
*/

void test1()
{
    printf("Memory size occupied by status : %ld\n", sizeof(status));
    printf("Memory size occupied by status1 : %ld\n", sizeof(status1));
}

/*
在结构内声明位域的形式如下：
struct
{
  type [member_name] : width ;
};
type	    只能为 int(整型)，unsigned int(无符号整型)，signed int(有符号整型) 三种类型，决定了如何解释位域的值。
member_name 位域的名称。
width       位域中位的数量。宽度必须小于或等于指定类型的位宽度。
*/

/*
带有预定义宽度的变量被称为位域。位域可以存储多于 1 位的数.
例如，需要一个变量来存储从 0 到 7 的值，您可以定义一个宽度为 3 位的位域
*/

struct Age
{
    unsigned int age : 3;
};

void test2()
{
    struct Age sAge, *pAge;
    sAge.age = 4;
    printf("Sizeof( sAge ) : %ld\n", sizeof(sAge));
    printf("sAge.age : %d\n", sAge.age);

    sAge.age = 7;
    pAge = &sAge;
    printf("sAge.age : %d\n", sAge.age);
    printf("sAge.age : %d\n", pAge->age);
    
    sAge.age = 8;
    printf("sAge.age : %d\n", sAge.age); // 编译警告： 大整数隐式截断为无符号类型
}
/*
Sizeof( Age ) : 4
Age.age : 4
Age.age : 7
Age.age : 0
*/

void main()
{
    printf("test 111111111111 \n");
    // test1();

    printf("\ntest 222222222222222 \n");
    test2();
}
