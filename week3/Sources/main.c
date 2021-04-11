#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

int main() {
	void menu();
	int key = 1, i = 0;
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	InitLQueue(Q);
	printf("           *欢迎来到队列系统*            \n\n");
	while (key) {
		menu();
		scanf_s("%d", &key);
		switch (key)
		{
		case 1: {
			if (!TraverseLQueue(Q, &LPrint))
				printf("队列为空！\n");
			break;
		}
		case 2: {
			if (IsEmptyLQueue(Q))
				printf("队列为空\n");
			else
				printf("队列不为空\n");
			break;
		}
		case 3: {
			void* e=malloc(sizeof(char));
			if (!GetHeadLQueue(Q, e))
				printf("队列为空");
			printf("\n");
			break;
		}
		case 4: {
			int n = 0;
			n = LengthLQueue(Q);
			printf("队列长度为:%d\n", n);
			break;
		}
		case 5: {
			void* d=malloc(sizeof(char));
			printf("请输入要入队的元素：");
			getchar();
			scanf_s("%c", (char*)d);
			if (EnLQueue(Q, d))
				printf("入队成功！\n");
			i++;
			break;
		}
		case 6: {
			if (DeLQueue(Q))
				printf("出队成功！\n");
			else
				printf("队列为空，无法出队\n");
			break;
		}
		case 7: {
			ClearLQueue(Q);
			printf("队列已清空\n");
			break;
		}
		case 0:
			break;
		default:
			printf("请输入数字0~8\n");
			break;
		}
	}
	DestoryLQueue(Q);
	return 0;
}

void menu() {
	printf("-----------------------------------------\n\n");
	printf("菜单：\n");
	printf("1、遍历队列\n");
	printf("2、检查队列是否为空\n");
	printf("3、查看队头元素\n");
	printf("4、确定队列长度\n");
	printf("5、入队\n");
	printf("6、出队\n");
	printf("7、清空队列\n");
	printf("0、退出\n\n");
	printf("-----------------------------------------\n\n");
	printf("请输入对应序号：");
}
