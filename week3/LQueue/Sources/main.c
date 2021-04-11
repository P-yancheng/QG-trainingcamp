#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

int main() {
	void menu();
	int key = 1, i = 0;
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	InitLQueue(Q);
	printf("           *��ӭ��������ϵͳ*            \n\n");
	while (key) {
		menu();
		scanf_s("%d", &key);
		switch (key)
		{
		case 1: {
			if (!TraverseLQueue(Q, &LPrint))
				printf("����Ϊ�գ�\n");
			break;
		}
		case 2: {
			if (IsEmptyLQueue(Q))
				printf("����Ϊ��\n");
			else
				printf("���в�Ϊ��\n");
			break;
		}
		case 3: {
			void* e=malloc(sizeof(char));
			if (!GetHeadLQueue(Q, e))
				printf("����Ϊ��");
			printf("\n");
			break;
		}
		case 4: {
			int n = 0;
			n = LengthLQueue(Q);
			printf("���г���Ϊ:%d\n", n);
			break;
		}
		case 5: {
			void* d=malloc(sizeof(char));
			printf("������Ҫ��ӵ�Ԫ�أ�");
			getchar();
			scanf_s("%c", (char*)d);
			if (EnLQueue(Q, d))
				printf("��ӳɹ���\n");
			i++;
			break;
		}
		case 6: {
			if (DeLQueue(Q))
				printf("���ӳɹ���\n");
			else
				printf("����Ϊ�գ��޷�����\n");
			break;
		}
		case 7: {
			ClearLQueue(Q);
			printf("���������\n");
			break;
		}
		case 0:
			break;
		default:
			printf("����������0~8\n");
			break;
		}
	}
	DestoryLQueue(Q);
	return 0;
}

void menu() {
	printf("-----------------------------------------\n\n");
	printf("�˵���\n");
	printf("1����������\n");
	printf("2���������Ƿ�Ϊ��\n");
	printf("3���鿴��ͷԪ��\n");
	printf("4��ȷ�����г���\n");
	printf("5�����\n");
	printf("6������\n");
	printf("7����ն���\n");
	printf("0���˳�\n\n");
	printf("-----------------------------------------\n\n");
	printf("�������Ӧ��ţ�");
}