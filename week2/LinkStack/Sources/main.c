#include"LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void menu();
void traverse(LinkStack*);

int main() {
	int key = 1;
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	s->count = -1;
	Status flag;
	while (key) {
		menu();
		scanf_s("%d", &key);
		switch (key) {
		case 1: {
			flag = initLStack(s);
			if (flag == SUCCESS)
				printf("The stack has been initialize >_<^\n");
			else
				printf("ERROR!");
			break;
		}
		case 2: {
			if (s->count==-1) {
				printf("The linked stack is NULL!\nPlease initialize first!\n");
			}
			else {
				flag = isEmptyLStack(s);
				if (flag = ERROR)
					printf("The stack is not empty.\n");
				else
					printf("The stack is empty!\n");
			}
			break;
		}
		case 3: {
			if (s->count == -1) {
				printf("The stack is NULL!\nPlease initialize first!\n");
				break;
			}
			else {
				ElemType* e = (ElemType*)malloc(sizeof(ElemType));
				flag = getTopLStack(s, e);
				if (flag == ERROR)
					printf("There is no element in the stack!");
				else
					printf("The element is: %d", *e);
			}
			break;
		}
		case 4: {
			if (s->count == -1) {
				printf("The stack is NULL!\nPlease initialize first!\n");
				break;
			}
			else {
				int* length = (int*)malloc(sizeof(int));
				flag = LStackLength(s, length);
				if (flag = SUCCESS)
					printf("The stack's length is: %d", *length);
				else
					printf("ERROE!");
			}
			break;
		}
		case 5: {
			if (s->count == -1) {
				printf("The stack is NULL!\nPlease initialize first!\n");
				break;
			}
			else {
				ElemType e;
				printf("Input the element you want to push:");
				scanf_s("%d", &e);
				flag = pushLStack(s, e);
				if (flag == ERROR)
					printf("ERROR! Cannot push\n");
				else {
					printf("Push completed!\nNow the stack: \n");
					traverse(s);
				}
			}
			break;
		}
		case 6: {
			if (s->count == -1) {
				printf("The stack is NULL!\nPlease initialize first!\n");
				break;
			}
			else {
				ElemType* data = (ElemType*)malloc(sizeof(ElemType));
				flag = popLStack(s, data);
				if (flag == ERROR)
					printf("The stack is empty! Cannot pop\n");
				else {
					printf("Pop completed!\n");
					printf("The poped element is: %d\n", *data);
				}
			}
			break;
		}
		case 7: {
			if (s->count == -1) {
				printf("The stack is NULL!\nPlease initialize first!\n");
				break;
			}
			flag = clearLStack(s);
			if (flag == SUCCESS)
				printf("The stack has been cleared\n");
			else
				printf("The stack has been NULL!\n");
			break;
		}
		case 8:
			if (s->count == -1) {
				printf("The stack is NULL!\nPlease initialize first!\n");
				break;
			}
			traverse(s);
			break;
		case 0: {
			destroyLStack(s);
			return 0;
		}
		default:
			printf("Please input the number 0 to 8");
			break;
		}
		Sleep(2000);
		system("cls");
	}
	destroyLStack(s);
	return 0;
}

void menu() {
	printf("---------------------------------------------\n\n");
	printf("    *Welcome to the linked stack system!*    \n\n");
	printf(" MENU:\n");
	printf(" 1.Initialize a stack.\n");
	printf(" 2.Judge if the stack is empty.\n");
	printf(" 3.Get the top element of the stack.\n");
	printf(" 4.Check the length of the stack.\n");
	printf(" 5.Push element to stack.\n");
	printf(" 6.Pop element to stack.\n");
	printf(" 7.Clear the stack.\n");
	printf(" 8.Traverse the stack.\n");
	printf(" 0.Exit.\n\n");
	printf("---------------------------------------------\n\n");
	printf("Please input the number for the function:\n");
}

void traverse(LinkStack* s) {
	if (s->top == NULL)
		printf("The stack is NULL!");
	else {
		printf("The stack is as follows:\n");
		LinkStackPtr p = s->top;
		while (p) {
			printf(" %d", p->data);
			p=p->next;
		}
		printf("\n");
	}
}
