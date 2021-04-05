#include<stdio.h>
#include"SqStack.h"
#include<stdlib.h>
#include<malloc.h>

//初始化栈
Status initStack(SqStack* s, int sizes) {
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));
	if (s->elem==NULL)
		return ERROR;
	s->top = -1;
	s->size = sizes;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyStack(SqStack* s) {
	if (s->top == -1)
		return SUCCESS;
	else
		return ERROR;
}

//得到栈顶元素
Status getTopStack(SqStack* s, ElemType* e) {
	if (s->top == -1)
		return ERROR;
	*e = s->elem[s->top];
	return SUCCESS;
}

//清空栈
Status clearStack(SqStack* s) {
	if (s == NULL)
		return ERROR;
	else
		s->top = -1;
	return SUCCESS;
}

//销毁栈
Status destroyStack(SqStack* s) {
	if (s == NULL)
		return ERROR;
	free(s->elem);
	s->elem = NULL;
	s->top = -1;
	s->size = 0;
	return SUCCESS;
}

//检测栈长度
Status stackLength(SqStack* s, int* length) {
	if (s->top>s->size-1)
		return ERROR;
	else
		*length = s->top + 1;
	return SUCCESS;
}

//入栈
Status pushStack(SqStack* s, ElemType data) {
	if ( s->top >= s->size - 1)
		return ERROR;
	s->elem[++s->top] = data;
	return SUCCESS;
}

//出栈
Status popStack(SqStack* s, ElemType* data) {
	if (s->top == -1)
		return ERROR;
	*data = s->elem[s->top--];
	return SUCCESS;
}
