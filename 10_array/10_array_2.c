// C 传递数组给函数

/*
如果您想要在函数中传递一个一维数组作为参数，您必须以下面三种方式来声明函数形式参数，这三种声明方式的结果是一样的，因为每种
方式都会告诉编译器将要接收一个整型指针。同样地，您也可以传递一个多维数组作为形式参数。
 */

/*
方式 1
形式参数是一个指针：

void myFunction(int *param)
{
   ...
}
 */

/*
方式 2
形式参数是一个已定义大小的数组：

void myFunction(int param[10])
{
   ...
}
 */

/*
方式 3
形式参数是一个未定义大小的数组：

void myFunction(int param[])
{
   ...
}
 */


#include <stdio.h>

// 指针的知识后续学习...
double getAverage1(int *arr, int size)
{
  int    i;
  double avg;
  double sum;
 
  for (i = 0; i < size; ++i)
  {
    sum += *(arr+i);
  }
 
  avg = sum / size;
 
  return avg;
}

double getAverage3(int arr[], int size)
{
  int    i;
  double avg;
  double sum;
 
  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
  }
 
  avg = sum / size;
 
  return avg;
}
int main ()
{
	
   /* 带有 5 个元素的整型数组 */
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
 
   /* 传递一个指向数组的指针作为参数 */
   avg = getAverage1(balance, 5) ;
   /* 输出返回值 */
   printf( "平均值是： %f\n ", avg );
    
   return 0;
}
