#include "duLinkedList.h"
#include<stdio.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L = (DuLinkedList)malloc(sizeof(DuLNode));  /*为头结点开辟一块区域*/
	if (!(*L))                                        /*失败则返回ERROR*/
		return ERROR;
	(*L)->next = NULL;
	(*L)->prior = NULL;                               /*前后指针为空*/
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p;
	while (*L) {
		p = (*L)->next;
		free(*L);
		*L = p;
		if (p)
			p->prior = NULL;
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if (!p)
		return ERROR;        /*确保p不为空（则p前结点也不为空）*/
	p->prior->next = q;
	q->prior = p->prior;     /*q与前一结点相连*/
	q->next = p;
	p->prior = q;            /*q与p相连*/
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if (!p)
		return ERROR;
	if (p->next) {                  /*p不是尾结点时，先将q与后面结点相接*/
		p->next->prior = q;
		q->next = p->next;
	}
	q->prior = p;                   /*p是尾结点时直接将q插入到p后*/
	p->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	DuLinkedList pe, pb;                       /*pe指向需删除结点，pb指向后一结点*/
	if (p->next==NULL)
		return ERROR;
	pe = p->next;
	pb = p->next->next;                        /*寻找pe，pb的位置*/
	p->next = pb;                              /*p为尾结点时，pb可以为NULL*/
	if (pb!=NULL) {
		pb->prior = p;                         /*p与后一结点pb相接*/
	}
	*e = pe->data;                             /*将对应值赋值给*e*/
	free(pe);                                  /*释放应删除结点*/
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList p;
	p = L->next;
	while (p != NULL) {
		visit(p->data);
		p = p->next;
	}
}
