#include <stdio.h>
#include <stdlib.h>

/*
一个文件，无论它是文本文件还是二进制文件，都是代表了一系列的字节。
C 语言不仅提供了访问顶层的函数，也提供了底层（OS）调用来处理存储设备上的文件。
*/

/*
打开文件: 可以使用 fopen() 函数来创建一个新的文件或者打开一个已有的文件，
这个调用会初始化类型 FILE 的一个对象，类型 FILE 包含了所有用来控制流的必要的信息。
FILE *fopen( const char * filename, const char * mode );

filename 是字符串，用来命名文件；
mode 表示访问模式，值可以是下列值中的一个：

模式	描述
r	打开一个已有的文本文件，允许读取文件。
w	打开一个文本文件，允许写入文件。如果文件不存在，则会创建一个新文件。在这里，程序会从文件的开头写入内容。如果文件存在，则该会被截断为零长度，重新写入。
a	打开一个文本文件，以追加模式写入文件。如果文件不存在，则会创建一个新文件。在这里，程序会在已有的文件内容中追加内容。
r+	打开一个文本文件，允许读写文件。
w+	打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。
a+	打开一个文本文件，允许读写文件。如果文件不存在，则会创建一个新文件。读取会从文件的开头开始，写入则只能是追加模式。

如果处理的是二进制文件，则需使用下面的访问模式来取代上面的访问模式：
"rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"
*/

/*
关闭文件: 使用 fclose( ) 函数。函数的原型如下：
 int fclose( FILE *fp );
 如果成功关闭文件，fclose( ) 函数返回零，如果关闭文件时发生错误，函数返回 EOF。
 实际上，这个函数会清空缓冲区中的数据，关闭文件，并释放用于该文件的所有内存。EOF 是一个定义在头文件 stdio.h 中的常量。
*/

/*
写入文件
下面是把字符写入到流中的最简单的函数：
int fputc( int c, FILE *fp );
函数 fputc() 把参数 c 的字符值写入到 fp 所指向的输出流中。如果写入成功，它会返回写入的字符，如果发生错误，则会返回 EOF。

也可以使用下面的函数来把一个以 null 结尾的字符串写入到流中：
int fputs( const char *s, FILE *fp );
*/

void test1()
{
    FILE *fp = NULL;
    fp = fopen("test.txt", "w+");
    // fputc(100, fp);
    // printf("finish write file by fputc \n");

    fputs("write file by fputs", fp);
    printf("finish write file by fputs \n");

    fclose(fp);
}

/*
读取文件
int fgetc( FILE * fp );
fgetc() 函数从 fp 所指向的输入文件中读取一个字符。返回值是读取的字符，如果发生错误则返回 EOF。

char *fgets( char *buf, int n, FILE *fp );
函数 fgets() 从 fp 所指向的输入流中读取 n - 1 个字符。它会把读取的字符串复制到缓冲区 buf，并在最后追加一个 null 字符来终止字符串。
如果这个函数在读取最后一个字符之前就遇到一个换行符 '\n' 或文件的末尾 EOF，则只会返回读取到的字符，包括换行符。
也可以使用 int fscanf(FILE *fp, const char *format, ...) 函数来从文件中读取字符串，但是在遇到第一个空格和换行符时，
它会停止读取。
*/
void test2()
{

    FILE *fp = NULL;
    fp = fopen("test.txt", "r");

    char buff[255];

    // fscanf(fp, "%s", buff);
    // printf("1: %s\n", buff);
    // 打印结果 1: write

    // fgets(buff, 255, fp);
    // printf("2: %s\n", buff);
    // 打印结果 2: write file by fputs

    int ret;
    ret = fgetc(fp);
    printf("3: %d\n", ret);
    // 打印结果 3： 119
    fclose(fp);
}

/*
二进制 I/O 函数
下面两个函数用于二进制输入和输出：

size_t fread(void *ptr, size_t size_of_elements, 
             size_t number_of_elements, FILE *a_file);
              
size_t fwrite(const void *ptr, size_t size_of_elements, 
             size_t number_of_elements, FILE *a_file);
*/

void main()
{

    printf("test 1111111111111() \n");
    // test1();

    printf("\ntest 2222222222222222() \n");
    test2();
}
