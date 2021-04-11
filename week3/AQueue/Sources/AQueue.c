#include<stdio.h>
#include"AQueue.h"

//��ʼ������
void InitAQueue(AQueue* Q) {
	Q->front = -1;
	Q->rear = -1;
	Q->length = 0;
}

//���ٶ���
void DestoryAQueue(AQueue* Q) {
	free(Q);
}

//�������Ƿ�����
Status IsFullAQueue(const AQueue* Q) {
	if (Q->length == MAXQUEUE)
		return TRUE;
	else
		return FALSE;
}

//�������Ƿ�Ϊ��
Status IsEmptyAQueue(const AQueue* Q) {
	if (Q->length == 0)
		return TRUE;
	else
		return FALSE;
}

//�鿴��ͷԪ��
Status GetHeadAQueue(AQueue* Q, void* e) {
	if (IsEmptyAQueue(Q))
		return FALSE;
	e = Q->data[Q->front+1];
	APrint(e);
	return TRUE;
}

//ȷ�����г���
int LengthAQueue(AQueue* Q) {
	return(Q->length);
}

//��Ӳ���
Status EnAQueue(AQueue* Q, void* data) {
	if (Q->length == MAXQUEUE)
		return FALSE;
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	Q->data[Q->rear] = data;
	Q->length++;
	return TRUE;
}

//���Ӳ���
Status DeAQueue(AQueue* Q) {
	if (Q->length == 0)
		return FALSE;
	Q->front=(Q->front + 1) % MAXQUEUE;
	Q->length--;
	return TRUE;
}

//��ն���
void ClearAQueue(AQueue* Q) {
	Q->front = -1;
	Q->rear = -1;
	Q->length = 0;
}

//������������
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q)) {
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i;
	for (i = (Q->front)+1;i <= Q->rear;i++)
		foo(Q->data[i]);
	printf("\n");
	return TRUE;
}

//��������
void APrint(void* q) {
	printf("%c ",*(char*)q);
}