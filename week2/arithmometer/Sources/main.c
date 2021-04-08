#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

#define MAX 100
void menu();

int main() {
	ElemType s[MAX],E[MAX];
	menu();
	printf("请输入一个中缀表达式：\n");
	gets_s(s,MAX-1);
	Transformmid(s, &E);
	printf("转换为后缀表达式为：\n");
	printf("%s\n", E);
	printf("后缀表达式的值为：\n");
	arithmetic(E);
	return 0;
}

void menu() {
	printf("-----------------------------------\n\n");
	printf("      欢迎使用四则运算计算器       \n\n");
	printf("-----------------------------------\n\n");
}
