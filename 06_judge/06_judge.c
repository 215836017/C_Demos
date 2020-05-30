/*
C 语言把任何非零和非空的值假定为 true，把零或 null 假定为 false。
 */

/*
C 语言提供了以下类型的判断语句:

if 语句:	        一个 if 语句 由一个布尔表达式后跟一个或多个语句组成。
if...else 语句:	一个 if 语句 后可跟一个可选的 else 语句，else 语句在布尔表达式为假时执行。
嵌套 if 语句:	可以在一个 if 或 else if 语句内使用另一个 if 或 else if 语句。
switch 语句: 	一个 switch 语句允许测试一个变量等于多个值时的情况。
嵌套switch语句:	可以在一个 switch 语句内使用另一个 switch 语句。
 */

/*
三元运算符(? :)也是条件运算符,可以用来替代 if...else 语句。它的一般形式如下：
Exp1 ? Exp2 : Exp3;
 */

/*
一个 if 语句 后可跟一个可选的 else 语句，else 语句在布尔表达式为 false 时执行。
C 语言中 if...else 语句的语法：

if(boolean_expression)
{
   // 如果布尔表达式为真将执行的一行或多行语句 
}
else
{
   // 如果布尔表达式为假将执行的一行或多行语句 
}
 */

/*
一个 switch 语句允许测试一个变量等于多个值时的情况。每个值称为一个 case，且被测试的变量会对每个 switch case 进行检查。
switch 语句必须遵循下面的规则：
1. switch 语句中的 expression 是一个常量表达式，必须是一个整型或枚举类型。
2. 在一个 switch 中可以有任意数量的 case 语句。每个 case 后跟一个要比较的值和一个冒号。
3. case 的 constant-expression 必须与 switch 中的变量具有相同的数据类型，且必须是一个常量或字面量。
4. 当被测试的变量等于 case 中的常量时，case 后跟的语句将被执行，直到遇到 break 语句为止。
5. 当遇到 break 语句时，switch 终止，控制流将跳转到 switch 语句后的下一行。
6. 不是每一个 case 都需要包含 break。如果 case 语句不包含 break，控制流将会 继续 后续的 case，直到遇到 break 为止。
7. 一个 switch 语句可以有一个可选的 default case，出现在 switch 的结尾。default case 可用于在上面所有 case 都不为真时
执行一个任务。default case 中的 break 语句不是必需的。
 */

void testSwitch(){
	/* 局部变量定义 */
   char grade = 'B';
 
   switch(grade)
   {
   case 'A' :
      printf("很棒！\n" );
      break;
   case 'B' :
   case 'C' :
      printf("做得好\n" );
      break;
   case 'D' :
      printf("您通过了\n" );
      break;
   case 'F' :
      printf("最好再试一下\n" );
      break;
   default :
      printf("无效的成绩\n" );
   }
   printf("您的成绩是 %c\n", grade );
 
}

void testIf(){
	/* 局部变量定义 */
   int a = 100;
 
   /* 检查布尔条件 */
   if( a < 20 )
   {
       /* 如果条件为真，则输出下面的语句 */
       printf("a 小于 20\n" );
   }
   else
   {
       /* 如果条件为假，则输出下面的语句 */
       printf("a 大于 20\n" );
   }
   printf("a 的值是 %d\n", a);
}

void testIfelse(){
	  /* 局部变量定义 */
   int a = 100;
 
   /* 检查布尔条件 */
   if( a == 10 )
   {
       /* 如果 if 条件为真，则输出下面的语句 */
       printf("a 的值是 10\n" );
   }
   else if( a == 20 )
   {
       /* 如果 else if 条件为真，则输出下面的语句 */
       printf("a 的值是 20\n" );
   }
   else if( a == 30 )
   {
       /* 如果 else if 条件为真，则输出下面的语句 */
       printf("a 的值是 30\n" );
   }
   else
   {
       /* 如果上面条件都不为真，则输出下面的语句 */
       printf("没有匹配的值\n" );
   }
   printf("a 的准确值是 %d\n", a );
 
}
void main(){
	testIf();

	testIfelse();

	testSwitch();
}