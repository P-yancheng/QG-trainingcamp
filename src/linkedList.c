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
	*L = (LinkedList)malloc(sizeof(LNode));		        /*给头结点申请空间*/
	if (!(*L))											/*若申请失败返回ERROR*/
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
	LinkedList p1, p2;          /*定义两个指针依次移动删除结点，p2在前，p1在后*/
	p1 = p2 = *L;
	while (p2 != NULL)          /*所有结点已释放后，删除完毕停止循环*/
	{
		p2 = p2->next;
		free(p1);
		p1 = p2;
	}
	free(p2);
	free(p1);                   /*再次释放空间，保证指针安全*/
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if (p->next == NULL) {                /*p是最后一个结点时，q接在p后作为尾结点*/
		p->next = q;
		q->next = NULL;
	}
	else {                                /*P不是最后一个结点时，q指向下一个结点*/
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
	if (pe == NULL)                 /*判断p后是否有结点*/
		return ERROR;               
	else {                          /*从链表中移除结点，将data值给e*/
		*e = pe->data;
		p->next = pe->next;
	}
	free(pe);                       /*释放已移除的结点*/
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
	int n=0,flag=0;                                          /*n为计序变量，flag为查找标记变量*/
	while (p != NULL) {
		if (p->data == e) {
			printf("Find it!\nIt is the %dth node", n);     /*查找成功*/
			flag=1;
			break;
		}
		p = p->next;
		n++;
	}
	if (flag == 0) {                                        /*未查找到*/
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
	LinkedList head = *L;           /*记录下头结点*/
	if (head == NULL) {
		return ERROR;
	}
	LinkedList pre, now, beh;      /*定义前中后三个指针进行链表反转*/
	pre = head->next;
	now = pre->next;
	pre->next = NULL;              /*第一个结点作为新的尾结点，记得加NULL*/
	while (now!=NULL){             
		beh = now->next;           /*记录next结点*/
		now->next = pre;           /*后一个结点指向前一个结点*/
		pre = now;
		now = beh;                 /*依次后移*/
	}
	head->next = pre;              /*头结点再次指向第一个结点*/
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
	LinkedList fp, sp;           /*定义一对快慢指针*/
	fp = head->next;             /*快指针快一步*/
	sp = head;
	while (fp!=NULL) {
		if (fp == sp) {          /*快指针套圈慢指针证明成环*/
			return SUCCESS;
		}
		fp = fp->next;
		sp = sp->next;           /*慢指针走一步*/
		if (fp) {
			fp = fp->next;       /*快指针走两步*/
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
	p2 = p1->next;                      /*p2在前，p1在后*/
	while (p2!=NULL&&p1!=NULL) {        /*NULL表示链表已到尾部*/
		p1->next = p2->next;
		p2->next = p1;
		p0->next = p2;                  /*这三步是交换相邻结点的位置*/
		p0 = p1;
		p1 = p1->next;                  /*p0，p1依次后移*/
		if (p1 != NULL)                 /*偶数个结点时，在尾部p1==NULL*/
			p2 = p1->next;              /*其他情况p2都可以依次后移*/
		else                            
			p2 = NULL;                  /*偶数个结点尾部时，确保p2==NULL*/
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
	fp = sp = head->next;                      /*跳过头结点，从第一个结点开始*/
	while (fp != NULL && fp->next != NULL) {   /*奇数个结点则fp->next==NULL,偶数个则fp==NULL （不算头结点）*/
		fp = fp->next->next;
		sp = sp->next;                         /*快指针走两步，慢指针走一步（偶数个结点时慢指针多走一步到后面一个）*/
	}
	return sp;                                 /*奇数个结点则返回中间结点，偶数个结点则返回中间两节点的后一个*/
}

