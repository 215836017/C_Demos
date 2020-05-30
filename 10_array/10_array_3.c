//C 从函数返回数组

/*
C 语言不允许返回一个完整的数组作为函数的参数。但是，可以通过指定不带索引的数组名来返回一个指向数组的指针。我们将在后续章节中讲解
有关指针的知识，可以先跳过本章，等了解了 C 指针的概念之后，再来学习本章的内容。

如果您想要从函数返回一个一维数组，您必须声明一个返回指针的函数，如下：
int * myFunction()
{
   ...
}
另外，C 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
/* 要生成和返回随机数的函数 */
int * getRandom()    
{
  static int  r[10];
  int i;
 
  /* 设置种子 */
  srand( (unsigned)time( NULL ) );
  for ( i = 0; i < 10; ++i)
  {
     r[i] = rand();
     printf( "r[%d] = %d\n", i, r[i]);
 
  }
 
  return r;
}
int *getRandom1()
{
  static int  r[10];
  int i;
 
  /* 设置种子 */
  srand( (unsigned)time( NULL ) );
  for ( i = 0; i < 10; ++i)
  {
     r[i] = rand();
     printf( "r[%d] = %d\n", i, r[i]);
 
  }
 
  return r;
}
 

int main ()
{
   /* 一个指向整数的指针 */
   int *p;
   int i;
 
   p = getRandom();
  // p = getRandom1(); 、、 getRandom() 和 getRandom1() 写法中，函数名中*的位置，并且两者是等效的。
   for ( i = 0; i < 10; i++ )
   {
       printf( "*(p + %d) : %d\n", i, *(p + i));
   }
 
   return 0;
}