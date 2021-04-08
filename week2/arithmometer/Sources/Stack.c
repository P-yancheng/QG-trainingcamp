#include"Stack.h"
#include<stdio.h>

//��ʼ��ջ
Status initLStack(LinkStack* s) {
	if (!s)
		return ERROR;
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	return(s->top == NULL);
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (!s->top)
		return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

//����ջ
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

//��ջ
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

//��ջ
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