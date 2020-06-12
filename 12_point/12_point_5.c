#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// C 允许您从函数返回指针: C 允许函数返回指针到局部变量、静态变量和动态内存分配。

/*
C 允许您从函数返回指针。为了做到这点，必须声明一个返回指针的函数，如下所示：
int * myFunction()
{
    ...
}

另外，C 语言不支持在调用函数时返回局部变量的地址，除非定义局部变量为 static 变量。
 */


/*
函数getRandom()中，它会生成 10 个随机数，并使用表示指针的数组名（即第一个数组元素的地址）来返回它们，
 */
int* getRandom(){
	static int r[10];
	int i;
 
   /* 设置种子 */
   srand( (unsigned)time( NULL ) );
   for ( i = 0; i < 10; ++i)
   {
      r[i] = rand();
      printf("r[%d] = %d\n", i, r[i]);
   }
 
   return r;
}


void main(){
	/* 一个指向整数的指针 */
   int *p;
   int i;

   p = getRandom();

   for(i=0; i<10; i++)
   {
   	  printf("*(p + [%d]): %d\n", i, *(p+i));
   }
}

