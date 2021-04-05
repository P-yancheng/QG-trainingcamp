#include"SqStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void menu();
void traverse(SqStack* s);

int main(){
	int key=1;
	SqStack* s = (SqStack*)malloc(sizeof(SqStack));
	s->elem = NULL;
	Status flag;
	while (key) {
		menu();
		scanf_s("%d", &key);
		switch (key) {
			case 1: {
				int size;
				printf("Input the sizes you want to creat:\n");
				scanf_s("%d", &size);
				flag = initStack(s, size);
				if (flag == SUCCESS)
					printf("The stack has been initialize >_<^\n");
				else
					printf("ERROR!");
				Sleep(2000);
				break;
			}
			case 2: {
				if (!s->elem) {
					printf("The stack is NULL!\nPlease initialize first!\n");
				}
				else {
					flag = isEmptyStack(s);
					if (flag = ERROR)
						printf("The stack is not empty.\n");
					else
						printf("The stack is empty!\n");
				}
				break;
			}
			case 3: {
				if (!s->elem) {
					printf("The stack is NULL!\nPlease initialize first!\n");
					break;
				}
				else {
					ElemType* e = (ElemType*)malloc(sizeof(ElemType));
					flag = getTopStack(s, e);
					if (flag == ERROR)
						printf("There is no element in the stack!");
					else
						printf("The element is: %d", *e);
				}
				break;
			}
			case 4: {
				if (!s->elem) {
					printf("The stack is NULL!\nPlease initialize first!\n");
					break;
				}
				else {
					int* length = (int*)malloc(sizeof(int));
					flag = stackLength(s, length);
					if (flag = SUCCESS)
						printf("The stack's length is: %d", *length);
					else
						printf("The length is out!");
				}
				break;
			}
			case 5: {
				if (s->elem==NULL) {
					printf("The stack is NULL!\nPlease initialize first!\n");
					break;
				}
				else {
					ElemType e;
					if (s->top == s->size - 1) {
						printf("The stack is full! Cannot push\n");
						break;
					}
					printf("Input the element you want to push:");
					scanf_s("%d", &e);
					flag = pushStack(s, e);
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
				if (!s->elem) {
					printf("The stack is NULL!\nPlease initialize first!\n");
					break;
				}
				else {
					ElemType* data = (ElemType*)malloc(sizeof(ElemType));
					flag = popStack(s, data);
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
				if (s->elem == NULL) {
					printf("The stack is NULL!\nPlease initialize first!\n");
					break;
				}
				flag = clearStack(s);
				if (flag == SUCCESS)
					printf("The stack has been cleared\n");
				else
					printf("The stack is NULL!\nPlease initialize first!\n");
				break;
			}
			case 8:
				if (s->elem == NULL) {
					printf("The stack is NULL!\nPlease initialize first!\n");
					break;
				}
				traverse(s);
				break;
			case 0: {
				destroyStack(s);
				return 0;
			}
			default:
				printf("Please input the number 0 to 8");
				break;
		}
		Sleep(2000);
		system("cls");
	}
	destroyStack(s);
	return 0;
}

void menu(){
	printf("--------------------------------------\n\n");
	printf("    *Welcome to the stack system!*    \n\n");
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
	printf("--------------------------------------\n\n");
	printf("Please input the number for the function:\n");
}

void traverse(SqStack* s) {
	if (s->top == -1)
		printf("The stack is NULL!");
	else {
		printf("The stack is as follows:\n");
		int n = s->top;
		while (n != -1) {
			printf(" %d", s->elem[n]);
			n--;
		}
		printf("\n");
	}
}
