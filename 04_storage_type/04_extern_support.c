#include <stdio.h>
 
extern int count1 = 10;  //  警告： ‘count1’已初始化，却又被声明为‘extern’ [默认启用]
extern int count2 = 10;  // 
extern int count3;
extern int count4;

void write_extern()
{
   printf("count1 11 is %d\n", count1);
   printf("count2 222 is %d\n", count2);
   printf("count3 3333 is %d\n", count3);
   printf("count4 44444 is %d\n", count4);
}
/*
count1 11 is 10
count2 222 is 25
count3 3333 is 35
count4 44444 is 0
 */