#include<stdio.h>
#include"LQueue.h"

//初始化队列
void InitLQueue(LQueue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

//销毁队列
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

//检查队列是否为空
Status IsEmptyLQueue(const LQueue* Q) {
    return(Q->length == 0);
}

//查看队头元素
Status GetHeadLQueue(LQueue* Q, void* e) {
    if (IsEmptyLQueue(Q))
        return FALSE;
    e = Q->front->data;
    LPrint(e);
    return TRUE;
}

//确定队列长度
int LengthLQueue(LQueue* Q) {
    return(Q->length);
}

//入队操作
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

//出队操作
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

//清空队列
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

//遍历函数操作
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

//操作函数
void LPrint(void* q) {
    printf("%c ", *(char*)q);
}
