#include<stdio.h>

extern int testX;
extern int testY;

int addFun(){
	return testX + testY + 10000000;
}