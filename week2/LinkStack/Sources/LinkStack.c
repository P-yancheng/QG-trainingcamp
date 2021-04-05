#include"LinkStack.h"
#include<stdio.h>

//初始化栈
Status initLStack(LinkStack* s) {
	if (!s)
		return ERROR;
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	return(s->top == NULL);
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (!s->top)
		return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack* s) {
	if (s->top == NULL)
		return ERROR;
	LinkStackPtr p1, p2;
	p1 = s->top;
	p2 = p1->next;
	while (p2) {
		free(p1);
		p1 = p2;
		p2 = p2->next;
	}
	free(p1);
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack* s) {
	if (!s)
		return ERROR;
	if (s->top == NULL) {
		free(s);
	}
	else {
		LinkStackPtr p1, p2;
		p1 = s->top;
		p2 = p1->next;
		while (p2) {
			free(p1);
			p1 = p2;
			p2 = p2->next;
		}
		free(p1);
		free(s);
	}
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length) {
	if (!s)
		return ERROR;
	*length = s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data) {
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!p)
		return ERROR;
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack* s, ElemType* data) {
	if (s->top == NULL)
		return ERROR;
	LinkStackPtr p = s->top;
	*data = p->data;
	s->top = p->next;
	free(p);
	s->count--;
	return SUCCESS;
}
