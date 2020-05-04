#include <stdio.h>
 
/* 函数声明 */
void func1(void); 
 
static int count=10; //全局变量 - static 是默认的 
 
int main()
{
  while (count--) {
      func1();
  }
  return 0;
}
 
void func1()
{
/* 'thingy' 是 'func1' 的局部变量 ---但是被static修饰后, 就是这个文件中的全局变量了, 它只初始化一次
 * 每次调用函数 'func1'时 'thingy' 值不会被重置, 但是会被运算.
 */                
  static int thingy=5;
  thingy++;
  printf(" thingy 为 %d ， count 为 %d\n", thingy, count);

}
/*
 thingy 为 6 ， count 为 9
 thingy 为 7 ， count 为 8
 thingy 为 8 ， count 为 7
 thingy 为 9 ， count 为 6
 thingy 为 10 ， count 为 5
 thingy 为 11 ， count 为 4
 thingy 为 12 ， count 为 3
 thingy 为 13 ， count 为 2
 thingy 为 14 ， count 为 1
 thingy 为 15 ， count 为 0

 */