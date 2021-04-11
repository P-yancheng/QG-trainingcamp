#include<stdio.h>
#include<stdlib.h>
#include"AQueue.h"

int main() {
	void menu();
	int key = 1,i=0;
	char data[MAXQUEUE];
	AQueue* Q = (AQueue*)malloc(sizeof(AQueue));
	InitAQueue(Q);
	printf("           *欢迎来到队列系统*            \n\n");
	while (key) {
		menu();
		scanf_s("%d",&key);
		switch (key)
		{
		case 1: {
			if (IsFullAQueue(Q))
				printf("队列已满\n");
			else
				printf("队列未满\n");
			break;
		}
		case 2: {
			if (IsEmptyAQueue(Q))
				printf("队列为空\n");
			else
				printf("队列不为空\n");
			break;
		}
		case 3: {
			void* e=malloc(sizeof(type));
			if (!GetHeadAQueue(Q, e))
				printf("队列为空");
			printf("\n");
			break;
		}
		case 4: {
			int n = 0;
			n = LengthAQueue(Q);
			printf("队列长度为:%d\n", n);
			break;
		}
		case 5: {
			void* d[MAXQUEUE];
			if (IsFullAQueue(Q))
				printf("队列已满，无法入队！\n");
			else {
				printf("请输入要入队的元素：");
				getchar();
				scanf_s("%c",&data[Q->length]);
				d[i] = &data[Q->length];
				if (EnAQueue(Q, d[i]))
					printf("入队成功！\n");
				i++;
			}
			break;
		}
		case 6: {
			if (DeAQueue(Q))
				printf("出队成功！\n");
			else
				printf("队列为空，无法出队\n");
			break;
		}
		case 7: {
			ClearAQueue(Q);
			break;
		}
		case 8: {
			if (!TraverseAQueue(Q,&APrint))
				printf("队列为空！\n");
			break;
		}
		case 0:
			break;
		default:
			printf("请输入数字0~8\n");
			break;
		}
	}
	DestoryAQueue(Q);
	return 0;
}

void menu() {
	printf("-----------------------------------------\n\n");
	printf("菜单：\n");
	printf("1、检查队列是否已满\n");
	printf("2、检查队列是否为空\n");
	printf("3、查看队头元素\n");
	printf("4、确定队列长度\n");
	printf("5、入队\n");
	printf("6、出队\n");
	printf("7、清空队列\n");
	printf("8、遍历队列\n");
	printf("0、退出\n\n");
	printf("-----------------------------------------\n\n");
	printf("请输入对应序号：");
}
