#include <stdio.h>
#include <string.h>

// 字符串

/*
在 C 语言中，字符串实际上是使用 null 字符 '\0' 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。
下面的声明和初始化创建了一个 "Hello" 字符串。由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个。
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

依据数组初始化规则，您可以把上面的语句写成以下语句：
char greeting[] = "Hello";
 */

// 其实，您不需要把 null 字符放在字符串常量的末尾。C 编译器会在初始化数组时，自动把 '\0' 放在字符串的末尾。

/*
C 中有大量操作字符串的函数：
1	strcpy(s1, s2);   复制字符串 s2 到字符串 s1。
2	strcat(s1, s2);   连接字符串 s2 到字符串 s1 的末尾。
3	strlen(s1);       返回字符串 s1 的长度。
4	strcmp(s1, s2);   如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
5	strchr(s1, ch);   返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
6	strstr(s1, s2);   返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。
*/
void test1(){
    char msg1[6] = {'H', 'e', 'e', 'l', 'l', 'o','o','o', '\0'};
    char msg2[6] = {'H', 'e', 'e', '\0','l', 'l', 'o','o','o'};
    printf("msg1 = %s\n", msg1);
    printf("msg2 = %s\n", msg2);
    
    /*
    结果：
    msg1 = Heello
    msg2 = Hee

    结论：未超过长度时，以结尾符号为准。 超过长度时，以指定的长度为准
    */
}

void test2(){

    char str1[12] = "Hello";
    char str2[12] = "World";
    char str3[12];
    int len;

    // 复制str1到str3
    strcpy(str3, str1);
    printf("strcpy(str3, str1), str3 = %s\n\n", str3);

    /* 连接 str1 和 str2 */
    strcat(str1, str2);
    printf("strcat( str1, str2):   %s\n\n", str1);

    /* 连接后，str1 的总长度 */
    len = strlen(str1);
    printf("strlen(str1) :  %d\n", len );
}


void main(){

    printf("test 1111111111\n");
    test1();

    printf("\n\ntest 2222222222222\n");
    test2();
}