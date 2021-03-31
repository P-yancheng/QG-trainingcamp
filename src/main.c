#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void print(ElemType e);
void menu();
LinkedList creatlinkedlist(LinkedList);
void (*visit)(ElemType) = &(print);

int main()
{
	LinkedList *L = (LinkedList*)malloc(sizeof(LinkedList));
	int key=1;
	ElemType flag;
	flag=InitList(L);
	if (L!=NULL)
		printf("\nThe linked list has been initialize >_<^\n");
	while (key) {
		menu();
		scanf_s("%d", &key);
		switch (key)
		{
			case 1: {
				if (L == NULL)
					printf("ERROR!");
				*L = creatlinkedlist(L);
				break;
			}
			case 2: {
				LinkedList p=*L, q = (LinkedList)malloc(sizeof(LNode));
				ElemType pi, qi;
				printf("Input the data of the node which you want to insert behind it:\n");
				scanf_s("%d", &pi);
				while ((p->data != pi)&&(p!=NULL)) {
					p = p->next;
				}
				if (p == NULL) {
					printf("There is no data as %d", pi);
					break;
				}
				printf("Input the inserted data:");
				scanf_s("%d", &qi);
				q->data = qi;
				q->next = NULL;
				flag=InsertList(p, q);
				if (flag == ERROR) {
					printf("ERROR!");
				}
				else {
					printf("Insertion is completed!\nNow the linked list:\n");
					TraverseList(*L, visit);
				}
				Sleep(2000);
				break;
			}
			case 3: {
				LinkedList p=*L;
				ElemType *e=(ElemType*)malloc(sizeof(ElemType)),pi;
				printf("Input the data of the node which you want to delete behind it:");
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
					break;
				}
				flag=DeleteList(p, e);
				if (flag == ERROR) {
					printf("There is no node behind it!");
				}
				else {
					printf("Deletion is completed!\nThe data of the deleted node is : %d\n",*e);
					printf("Now the linked list:\n");
					TraverseList(*L, visit);
				}
				Sleep(2000);
				break;
			}
			case 4: {
				ElemType e;
				printf("Input the data to search:");
				scanf_s("%d",&e);
				SearchList(*L, e);
				Sleep(2000);
				break;
			}
			case 5: {
				flag=ReverseList(L);
				if (flag == SUCCESS) {
					printf("SUCCESS!\n");
					printf("Now the linked list:\n");
					TraverseList(*L, visit);
				}
				else printf("ERROR!\n");
				Sleep(2000);
				break;
			}
			case 6: {
				flag = IsLoopList(*L);
				if (flag == SUCCESS)
					printf("Yes!\n");
				else printf("No!\n");
				Sleep(2000);
				break;
			}
			case 4: {
				ElemType e;
				printf("Input the data to search:");
				scanf_s("%d",&e);
				SearchList(*L, e);
				Sleep(2000);
				break;
			}
			case 5: {
				flag=ReverseList(L);
				if (flag == SUCCESS) {
					printf("SUCCESS!\n");
					printf("Now the linked list:\n");
					TraverseList(*L, visit);
				}
				else printf("ERROR!\n");
				Sleep(2000);
				break;
			}
			case 6: {
				flag = IsLoopList(*L);
				if (flag == SUCCESS)
					printf("Yes!\n");
				else printf("No!\n");
				Sleep(2000);
				break;
			}
			case 7: {
				*L = ReverseEvenList(L);
				if (L != NULL) {
					printf("SUCCESS!\n");
					printf("Now the linked list:\n");
					TraverseList(*L, visit);
				}
				else printf("ERROR!\n");
				Sleep(2000);
				break;
			}
			case 8: {
				LinkedList m=NULL;
				m = FindMidNode(L);
				if (m != NULL)
					printf("It's data is %d\n", m->data);
				Sleep(2000);
				break;
			}
			case 9: {
				TraverseList(*L, visit);
				Sleep(5000);
				break;
			}
			case 0: {
				DestroyList(L);
				return 0;
			}
			default: {
				printf("Please input a number from 0 to 9 !\n");
				Sleep(2000);
			}
		}
		system("cls");
	}
	DestroyList(L);
	return 0;
}

void menu() {
	printf("-------------------------------------------\n\n");
	printf("      *Welcome to LinkedList system!*      \n\n");
	printf(" MENU:\n");
	printf(" 1.Creat a linked list\n");
	printf(" 2.Insert a node\n");
	printf(" 3.Delete a node\n");
	printf(" 4.Search a node\n");
	printf(" 5.Reverse the linked list\n");
	printf(" 6.Judge whether the linked list is looped\n");
	printf(" 7.Reverse the even nodes\n");
	printf(" 8.Find the middle node\n");
	printf(" 9.Print the linked list\n");
	printf(" 0 for exit!\n");
	printf("-------------------------------------------\n\n");
	printf("Please input the number for the function:\n");
}

LinkedList creatlinkedlist(LinkedList *L) {
	LinkedList p1=*L ,p2=(LinkedList)malloc(sizeof(LNode));
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
		if (!(p2->data))
			printf("assignment is error!");
		p1->next = p2;
		p1 = p2;
		p2 = (LinkedList)malloc(sizeof(LNode));
	}
	free(p2);
	printf("The creation of the linked list hes been completed!");
	Sleep(2000);
	return *L;
}

/*visit函数*/
void print(ElemType e) {
	printf(" %d", e);
}
