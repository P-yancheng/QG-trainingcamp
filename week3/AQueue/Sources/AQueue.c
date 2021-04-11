#include<stdio.h>
#include"AQueue.h"

//初始化队列
void InitAQueue(AQueue* Q) {
	Q->front = -1;
	Q->rear = -1;
	Q->length = 0;
}

//销毁队列
void DestoryAQueue(AQueue* Q) {
	free(Q);
}

//检查队列是否已满
Status IsFullAQueue(const AQueue* Q) {
	if (Q->length == MAXQUEUE)
		return TRUE;
	else
		return FALSE;
}

//检查队列是否为空
Status IsEmptyAQueue(const AQueue* Q) {
	if (Q->length == 0)
		return TRUE;
	else
		return FALSE;
}

//查看队头元素
Status GetHeadAQueue(AQueue* Q, void* e) {
	if (IsEmptyAQueue(Q))
		return FALSE;
	e = Q->data[Q->front+1];
	APrint(e);
	return TRUE;
}

//确定队列长度
int LengthAQueue(AQueue* Q) {
	return(Q->length);
}

//入队操作
Status EnAQueue(AQueue* Q, void* data) {
	if (Q->length == MAXQUEUE)
		return FALSE;
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	Q->data[Q->rear] = data;
	Q->length++;
	return TRUE;
}

//出队操作
Status DeAQueue(AQueue* Q) {
	if (Q->length == 0)
		return FALSE;
	Q->front=(Q->front + 1) % MAXQUEUE;
	Q->length--;
	return TRUE;
}

//清空队列
void ClearAQueue(AQueue* Q) {
	Q->front = -1;
	Q->rear = -1;
	Q->length = 0;
}

//遍历函数操作
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q)) {
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i;
	for (i = (Q->front)+1;i <= Q->rear;i++)
		foo(Q->data[i]);
	printf("\n");
	return TRUE;
}

//操作函数
void APrint(void* q) {
	printf("%c ",*(char*)q);
}