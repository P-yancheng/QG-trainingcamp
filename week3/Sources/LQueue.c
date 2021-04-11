#include<stdio.h>
#include"LQueue.h"

//��ʼ������
void InitLQueue(LQueue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

//���ٶ���
void DestoryLQueue(LQueue* Q) {
    Node* cur = Q->front;
    while (cur)
    {
        Q->front = Q->front->next;
        free(cur);
        cur = Q->front;
    }
    Q->front = NULL;
    Q->rear = NULL;
    free(Q);
}

//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q) {
    return(Q->length == 0);
}

//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue* Q, void* e) {
    if (IsEmptyLQueue(Q))
        return FALSE;
    e = Q->front->data;
    LPrint(e);
    return TRUE;
}

//ȷ�����г���
int LengthLQueue(LQueue* Q) {
    return(Q->length);
}

//��Ӳ���
Status EnLQueue(LQueue* Q, void* data) {
    Node *p=(Node*)malloc(sizeof(Node));
    if (p == NULL)
        return FALSE;
    p->data = data;
    p->next = NULL;
    if (Q->length == 0)
        Q->front = Q->rear = p;
    else {
        Q->rear->next = p;
        Q->rear = p;
    }
    Q->length++;
    return TRUE;
}

//���Ӳ���
Status DeLQueue(LQueue* Q) {
    Node* temp;
    if (IsEmptyLQueue(Q))
        return FALSE;
    temp = Q->front;
    Q->front = temp->next;
    if (Q->rear == temp)
        Q->rear = NULL;
    free(temp);
    Q->length--;
    return TRUE;
}

//��ն���
void ClearLQueue(LQueue* Q) {
    Node* cur = Q->front;
    while (cur)
    {
        Q->front = Q->front->next;
        free(cur);
        cur = Q->front;
    }
    Q->front = NULL;
    Q->rear = NULL;
}

//������������
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
    if (IsEmptyLQueue(Q))
        return FALSE;
    Node* p = Q->front;
    while (p != NULL) {
        foo(p->data);
        p = p->next;
    }
    printf("\n");
    return TRUE;
}

//��������
void LPrint(void* q) {
    printf("%c ", *(char*)q);
}
