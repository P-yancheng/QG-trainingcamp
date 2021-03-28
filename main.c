#include "linkedList.h"
#include<stdio.h>
#include "linkedlist.c"

void print(ElemType e);

int main()
{
	LinkedList L;
	int key=1;
	ElemType flag = SUCCESS;
	Status InitList(L);
	while (key) {
		menu();
		scanf("%d", key);
		switch (key)
		{
			case 1: {
				L = creatlinkedlist(L);
				break;
			}
			case 2: {
				LinkedList p, q = NULL;
				ElemType pi, qi;
				printf("input the data of the node which you want to insert behind it:");
				scanf("%d", &pi);
				p = L->next;
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
				printf("input the inserted data:");
				scanf("%d", &qi);
				q->data = qi;
				q->next = NULL;
				InsertList(p, q);
				break;
			}
			case 3: {
				LinkedList p;
				ElemType e=0;
				printf("input the data of the node which you want to delete behind it:");
				scanf("%d", &p);
				p = L->next;
				while (p != NULL) {
					if (p->data == p)
						break;
					else
						p = p->next;
				}
				if (p == NULL) {
					printf("There is no data as %d", p);
					break;
				}
				DeleteList(p, e);
				break;
			}
			case 4: {
				ElemType e;
				printf("input the data to search:");
				scanf("%d",&e);
				SearchList(L, e);
				break;
			}
			case 5: {
				flag=ReverseList(L);
				if (flag == SUCCESS)
					printf("SUCCESS!\n");
				else printf("ERROR!\n");
				break;
			}
			case 6: {
				flag = IsLoopList(L);
				if (flag == SUCCESS)
					printf("Yes!\n");
				else printf("No!\n");
				break;
			}
			case 7: {
				flag = ReverseEvenList( L);
				if (flag == SUCCESS)
					printf("SUCCESS!\n");
				else printf("ERROR!\n");
				break;
			}
			case 8: {
				LinkedList m=NULL;
				m = FindMidNode(L);
				if (m != NULL)
					printf("It's data is %d\n", m->data);
				break;
			}
			case 9: {
				void (*visit)(ElemType )=print;
				TraverseList(L, (*visit));
				break;
			}
			case 0: {
				DestroyList(L);
				return 0;
			}
			default: {
				printf("input the num from 0 to 9 !\n");
			}
		}
	}
	DestroyList(L);
	return 0;
}

void menu() {
	printf("-------------------------------------------\n\n");
	printf("      *Welcome to LinkedList system!*      \n\n");
	printf(" MENU:\n");
	printf(" 1.creat a linked list\n");
	printf(" 2.insert a node\n");
	printf(" 3.delete a node\n");
	printf(" 4.search a node\n");
	printf(" 5.reverse the linked list\n");
	printf(" 6.judge whether the linked list is looped\n");
	printf(" 7.reverse the even nodes\n");
	printf(" 8.find the middle node\n");
	printf(" 9.print the linked list\n");
	printf(" 0 for exit\n");
	printf("-------------------------------------------\n\n");
	printf("Please input the number for the function:\n");
}

LinkedList creatlinkedlist(LinkedList L) {
	LinkedList p1 = L,p2;
	int i,n;
	printf("Please input how much nodes do you want to creat:\n");
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		p2 = (LinkedList)malloc(sizeof(LNode));
		p1->next = p2;
		printf("input the data of the %dth nodes:\n");
		scanf("%d", &p2->data);
		p2->next = NULL;
		p1 = p2;
	}
	printf("The creation of the linked list hes been completed!");
	return L;
}

/*visitº¯Êý*/
void print(ElemType e) {
	printf("%d", e);
}
