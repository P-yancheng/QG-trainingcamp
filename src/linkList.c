#include "linkedList.h"
#include<stdio.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L = (LinkedList)malloc(sizeof(LNode));		        /*��ͷ�������ռ�*/
	if (!(*L))											/*������ʧ�ܷ���ERROR*/
		return ERROR;
	(*L)->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p1, p2;          /*��������ָ�������ƶ�ɾ����㣬p2��ǰ��p1�ں�*/
	p1 = p2 = *L;
	while (p2 != NULL)          /*���н�����ͷź�ɾ�����ֹͣѭ��*/
	{
		p2 = p2->next;
		free(p1);
		p1 = p2;
	}
	free(p2);
	free(p1);                   /*�ٴ��ͷſռ䣬��ָ֤�밲ȫ*/
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if (p->next == NULL) {                /*p�����һ�����ʱ��q����p����Ϊβ���*/
		p->next = q;
		q->next = NULL;
	}
	else {                                /*P�������һ�����ʱ��qָ����һ�����*/
		LinkedList pNext = p->next;
		p->next = q;
		q->next = pNext;
	}
	if (p->next == q)
		return SUCCESS;
	else
		return ERROR;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	LNode *pe;
	pe = p->next;
	if (pe == NULL)                 /*�ж�p���Ƿ��н��*/
		return ERROR;               
	else {                          /*���������Ƴ���㣬��dataֵ��e*/
		e = pe->data;
		p->next = pe->next;
	}
	free(pe);                       /*�ͷ����Ƴ��Ľ��*/
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LinkedList p;
	p = L->next;
	while (p!= NULL) {
		visit(p->data);
		p = p->next;
	}
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LinkedList p=L;
	int n=0,flag=0;                                          /*nΪ���������flagΪ���ұ�Ǳ���*/
	while (p != NULL) {
		if (p->data == e) {
			printf("Find it!\nIt is the %dth node", n);     /*���ҳɹ�*/
			flag=1;
			break;
		}
		p = p->next;
		n++;
	}
	if (flag == 0) {                                        /*δ���ҵ�*/
		printf("Have not find it!");
		return ERROR;
	}
	return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LinkedList head = *L;           /*��¼��ͷ���*/
	if (head == NULL) {
		return ERROR;
	}
	LinkedList pre, now, beh;      /*����ǰ�к�����ָ���������ת*/
	pre = head->next;
	now = pre->next;
	pre->next = NULL;              /*��һ�������Ϊ�µ�β��㣬�ǵü�NULL*/
	while (now!=NULL){             
		beh = now->next;           /*��¼next���*/
		now->next = pre;           /*��һ�����ָ��ǰһ�����*/
		pre = now;
		now = beh;                 /*���κ���*/
	}
	head->next = pre;              /*ͷ����ٴ�ָ���һ�����*/
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList head = L;
	if (head == NULL||head->next==NULL) {
		return ERROR;
	}
	LinkedList fp, sp;           /*����һ�Կ���ָ��*/
	fp = head->next;             /*��ָ���һ��*/
	sp = head;
	while (fp!=NULL) {
		if (fp == sp) {          /*��ָ����Ȧ��ָ��֤���ɻ�*/
			return SUCCESS;
		}
		fp = fp->next;
		sp = sp->next;           /*��ָ����һ��*/
		if (fp) {
			fp = fp->next;       /*��ָ��������*/
		}
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	LinkedList head = *L;
	LinkedList p0 = head, p1, p2;
	p1 = p0->next;
	p2 = p1->next;                      /*p2��ǰ��p1�ں�*/
	while (p2!=NULL&&p1!=NULL) {        /*NULL��ʾ�����ѵ�β��*/
		p1->next = p2->next;
		p2->next = p1;
		p0->next = p2;                  /*�������ǽ������ڽ���λ��*/
		p0 = p1;
		p1 = p1->next;                  /*p0��p1���κ���*/
		if (p1 != NULL)                 /*ż�������ʱ����β��p1==NULL*/
			p2 = p1->next;              /*�������p2���������κ���*/
		else                            
			p2 = NULL;                  /*ż�������β��ʱ��ȷ��p2==NULL*/
	}
	return head;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList head, fp, sp;
	head = *L;
	if (head == NULL)
		return NULL;
	fp = sp = head->next;                      /*����ͷ��㣬�ӵ�һ����㿪ʼ*/
	while (fp != NULL && fp->next != NULL) {   /*�����������fp->next==NULL,ż������fp==NULL ������ͷ��㣩*/
		fp = fp->next->next;
		sp = sp->next;                         /*��ָ������������ָ����һ����ż�������ʱ��ָ�����һ��������һ����*/
	}
	return sp;                                 /*����������򷵻��м��㣬ż��������򷵻��м����ڵ�ĺ�һ��*/
}


