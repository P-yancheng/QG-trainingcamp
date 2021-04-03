#include"duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void print(ElemType e);
void menu();
DuLinkedList creatDuLinkedList(DuLinkedList*);
void (*visit)(ElemType) = &(print);

int main()
{
	DuLinkedList *L = (DuLinkedList*)malloc(sizeof(DuLinkedList));
	int key=1;
	ElemType flag;
	flag= InitList_DuL(L);
	if ((*L)!=NULL)
		printf("\nThe double linked list has been initialize >_<^\n");
	while (key) {
		menu();
		scanf_s("%d", &key);
		if (key != 1 && (*L)->next == NULL) {
			printf("There is no linked list!\nPlease creat a linked list first!\n");
			Sleep(1000);
		}
		else
			switch (key)
			{
				case 1: {
					if (*L == NULL)
						printf("ERROR!");
					*L = creatDuLinkedList(L);
					break;
				}
				case 2: {
					DuLinkedList p=*L, q = (DuLinkedList)malloc(sizeof(DuLNode));
					ElemType pi, qi;
					printf("Input the data of the node which you want to insert before it:\n");
					scanf_s("%d", &pi);
					p = p->next;
					while (p != NULL) {
						if (p->data == pi)
							break;
						else
							p = p->next;
					}
					if (p == NULL) {
						printf("There is no data as %d", pi);
						Sleep(2000);
						break;
					}
					printf("Input the inserted data:");
					scanf_s("%d", &qi);
					q->data = qi;
					q->next = NULL;
					q->prior = NULL;
					flag= InsertBeforeList_DuL(p, q);
					if (flag == ERROR) {
						printf("ERROR!");
					}
					else {
						printf("Insertion is completed!\nNow the linked list:\n");
						TraverseList_DuL(*L, visit);
					}
					Sleep(2000);
					break;
				}
				case 3: {
					DuLinkedList p = *L, q = (DuLinkedList)malloc(sizeof(DuLNode));
					ElemType pi, qi;
					printf("Input the data of the node which you want to insert after it:\n");
					scanf_s("%d", &pi);
					p = p->next;
					while (p != NULL) {
						if (p->data == pi)
							break;
						else
							p = p->next;
					}
					if (p == NULL) {
						printf("There is no data as %d", pi);
						Sleep(2000);
						break;
					}
					printf("Input the inserted data:");
					scanf_s("%d", &qi);
					q->data = qi;
					q->next = NULL;
					q->prior = NULL;
					flag = InsertAfterList_DuL(p, q);
					if (flag == ERROR) {
						printf("ERROR!");
					}
					else {
						printf("Insertion is completed!\nNow the linked list:\n");
						TraverseList_DuL(*L, visit);
					}
					Sleep(2000);
					break;
				}
				case 4: {
					DuLinkedList p = *L;
					ElemType *e =(ElemType*)malloc(sizeof(ElemType)), n;
					printf("Which node do you want to delete? Input the serial number:\n");
					scanf_s("%d", &n);
					for (int i = 1;i < n;i++) {
						if (p->next == NULL)
							break;
						p = p->next;
					}
					if (p->next == NULL) {
						printf("%dth is out of range!", n);
						Sleep(2000);
						break;
					}
					flag = DeleteList_DuL(p, e);
					if (flag == ERROR) {
						printf("There is no node behind it!");
					}
					else {
						printf("Deletion is completed!\nNow the linked list:\n");
						TraverseList_DuL(*L, visit);
					}
					Sleep(2000);
					break;
				}
				case 5: {
					TraverseList_DuL(*L, visit);
					Sleep(5000);
					break;
				}
				case 0: {
					DestroyList_DuL(L);
					return 0;
				}
				default: {
					printf("Please input a number from 0 to 5 !\n");
					Sleep(2000);
				}
			}
		system("cls");
	}
	DestroyList_DuL(L);
	return 0;
}

void menu() {
	printf("-------------------------------------------\n\n");
	printf("      *Welcome to DuLinkedList system!*      \n\n");
	printf(" MENU:\n");
	printf(" 1.Creat a linked list\n");
	printf(" 2.Insert a node before some nodes\n");
	printf(" 3.Insert a node after some nodes\n");
	printf(" 4.Delete a node\n");
	printf(" 5.Print the linked list\n");
	printf(" 0 for exit!\n");
	printf("-------------------------------------------\n\n");
	printf("Please input the number for the function:\n");
}

DuLinkedList creatDuLinkedList(DuLinkedList *L) {
	DuLinkedList p1=*L ,p2=(DuLinkedList)malloc(sizeof(DuLNode));
	int i,n;
	printf("Please input how much nodes do you want to creat:\n");
	scanf_s("%d", &n);
	for (i = 1;i <= n;i++) {
		if (p2 == NULL) {
			printf("malloc error!");
			return NULL;
		}
		printf("input the data of the %dth nodes:",i);
		scanf_s("%d", &p2->data);
		p2->next = NULL;
		p2->prior = p1;
		p1->next = p2;
		p1 = p2;
		p2 = (DuLinkedList)malloc(sizeof(DuLNode));
	}
	free(p2);
	printf("The creation of the linked list has been completed!");
	Sleep(2000);
	return *L;
}

/*visit函数*/
void print(ElemType e) {
	printf(" %d", e);
}
