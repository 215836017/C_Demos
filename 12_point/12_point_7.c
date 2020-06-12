#include <stdlib.h>  
#include <stdio.h>

// C语音中的回调函数： 函数指针作为某个函数的参数

/*
函数指针变量可以作为某个函数的参数来使用的，回调函数就是一个通过函数指针调用的函数。

简单讲：回调函数是由别人的函数执行时调用你实现的函数。
 */

/*
下面的例子中，populate_array 函数定义了三个参数，其中第三个参数是函数的指针，通过该函数来设置数组的值。
实例中我们定义了回调函数 getNextRandomValue，它返回一个随机值，它作为一个函数指针传递给 populate_array 函数。
populate_array 将调用 10 次回调函数，并将回调函数的返回值赋值给数组。
 */


// 回调函数
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{   size_t i;
    for (i=0; i<arraySize; i++){
        array[i] = getNextValue();
    }
}
 
// 获取随机值
int getNextRandomValue(void)
{
    return rand();
}
 
int main(void)
{   
	int i;
    int myarray[10];
    populate_array(myarray, 10, getNextRandomValue);
    for(i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}