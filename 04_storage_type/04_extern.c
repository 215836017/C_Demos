#include <stdio.h>
 
int count1, count2, count3, count4;
extern void write_extern();
 
int main()
{
   count2 = 25;
   count3 = 35;
   write_extern();
}