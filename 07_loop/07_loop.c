/*
C 语言提供了以下几种循环类型:
while 循环:    	   当给定条件为真时，重复语句或语句组。它会在执行循环主体之前测试条件。
for 循环	:          多次执行一个语句序列，简化管理循环变量的代码。
do...while 循环:	   除了它是在循环主体结尾测试条件外，其他与 while 语句类似。
嵌套循环:      	   可以在 while、for 或 do..while 循环内使用一个或多个循环。
 */

/*
循环控制语句改变你代码的执行顺序。通过它你可以实现代码的跳转。C 提供了下列的循环控制语句：
break 语句：  	终止循环或 switch 语句，程序流将继续执行紧接着循环或 switch 的下一条语句。
continue 语句	告诉一个循环体立刻停止本次循环迭代，重新开始下次循环迭代。
goto 语句：  	将控制转移到被标记的语句。但是不建议在程序中使用 goto 语句。
 */

/*
 for 循环的语法：

for ( init; condition; increment )
{
   statement(s);
}


for 循环的控制流：
1. init 会首先被执行，且只会执行一次。这一步允许您声明并初始化任何循环控制变量。您也可以不在这里写任何语句，只要有一个分号出现即可。
2. 接下来，会判断 condition。如果为真，则执行循环主体。如果为假，则不执行循环主体，且控制流会跳转到紧接着 for 循环的下一条语句。
3. 在执行完 for 循环主体后，控制流会跳回上面的 increment 语句。该语句允许您更新循环控制变量。该语句可以留空，只要在条件后有一个分号出现即可。
4. 条件再次被判断。如果为真，则执行循环，这个过程会不断重复（循环主体，然后增加步值，再然后重新判断条件）。在条件变为假时，for 循环终止。
 */


/*
do...while 循环的语法：

do
{
   statement(s);

}while( condition );
请注意，条件表达式出现在循环的尾部，所以循环中的 statement(s) 会在条件被测试之前至少执行一次。
如果条件为真，控制流会跳转回上面的 do，然后重新执行循环中的 statement(s)。这个过程会不断重复，直到给定条件变为假为止。
 */


#include<stdio.h>

void testWhile(){
	/* 局部变量定义 */
   int a = 10;
printf("test while start...\n");
   /* while 循环执行 */
   while( a < 20 )
   {
      printf("a 的值： %d\n", a);
      a++;
   }
}

void testDoWhile(){
	 /* 局部变量定义 */
   int a = 10;
printf("\ntest do-while start...\n");
   /* do 循环执行 */
   do
   {
       printf("a 的值： %d\n", a);
       a = a + 1;
   }while( a < 20 );
}

void testFor(){
	printf("\ntest for start...\n");
	/* for 循环执行 */	
   for( int a = 10; a < 20; a = a + 1 )
   {
      printf("a 的值： %d\n", a);
   }
}

int main()
{
	testWhile();

    testDoWhile();

    testFor();

	return 0;
}