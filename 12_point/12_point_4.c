#include<stdio.h>

// 传递指针给函数: 通过引用或地址传递参数，使传递的参数在调用函数中被改变


/*
C 语言允许传递指针给函数，只需要简单地声明函数参数为指针类型即可。
通过传递指针给函数，可以直接修改原参数（实参），而不是引用实参到形参。

下面的实例中，我们传递一个无符号的 long 型指针给函数，并在函数内改变这个值：
 */

void getSeconds(unsigned long *par)
{
   /* 获取当前的秒数 */
   *par = time( NULL );
   return;
}


/*
能接受指针作为参数的函数，也能接受数组作为参数, 如test2()方法中所示：
 */
double  test2(int *arr, int size){
   int    i, sum = 0;       
  double avg;          
 
  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
  }
 
  avg = (double)sum / size;
 
  return avg;
}

int main ()
{
   unsigned long sec;
   
   /* 带有 5 个元素的整型数组  */
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;

   getSeconds( &sec );
   /* 输出实际值 */
   printf("Number of seconds: %ld\n", sec );


   printf("\n\ntest 2222222");
   /* 传递一个指向数组的指针作为参数 */
   avg = test2( balance, 5 ) ;
    /* 输出返回值  */
   printf("Average value is: %f\n", avg );

   return 0;
}