#include<stdio.h>
#include"Stack.h"

//��׺���ʽת��Ϊ��׺���ʽ
Status Transformmid (ElemType m[],ElemType (*E)[]) {
    int i=0,j=0;
    LinkStack* s= (LinkStack*)malloc(sizeof(LinkStack));      /*����������ŵ�ջ*/
    initLStack(s);
    ElemType e,d;                                             /*��¼ջ��Ԫ�غ�ȡ��ջ��Ԫ��*/
    Status J,flag=0;                                          /*�ж���ö�ٱ���*/
    for (i = 0;m[i] != '\0';i++) {                            /*������׺���ʽ��ÿ��Ԫ��*/
        if (m[i] >= '0' && m[i] <= '9') {
            (*E)[j++] = m[i];                                 /*����ֱ�Ӵ������*/
        }
        else if (Judge(SUCCESS, m[i]) != 0) {
            if (isEmptyLStack(s))
                pushLStack(s, m[i]);                          /*��ջ����ֱ����ջ*/
            else {
                getTopLStack(s, &e);
                if (Judge(SUCCESS, e) > Judge(ERROR, m[i])) {              /*�������ȼ���ʱ�������ȼ���ķ��������ջ*/
                    while (Judge(SUCCESS, e) > Judge(ERROR, m[i])) {
                        popLStack(s, &d);
                        (*E)[j++] = d;
                        if (isEmptyLStack(s)) {                            /*ֱ����ջΪֹ�������˷�����ջ*/
                            pushLStack(s, m[i]);
                            break;
                        }
                        getTopLStack(s, &e);
                        if (Judge(SUCCESS, e) == Judge(ERROR, m[i])) {     /*����������������ʱ��ֱ�ӵ�������ֵ*/
                            popLStack(s, &d);
                            break;
                        }
                    }
                }
                else if (Judge(SUCCESS, e) < Judge(ERROR, m[i])) {
                    pushLStack(s, m[i]);
                    e = m[i];
                }
                else                                          /*���ȼ����֤���������Դ����ţ���ֱ�ӳ�ջ�Ҳ�������ʽ*/
                    popLStack(s, &d);
            }
        }
        else continue;
    }
    while (!isEmptyLStack(s)) {                               /*��ջ��ʣ�µ�Ԫ�ص�ջ*/
        popLStack(s, &d);
        (*E)[j++] = d;
    }
    (*E)[j] = '\0';                                           /*����׺���ʽ������ӽ�����*/
    destroyLStack(s);
    if (!(*E))
        return ERROR;
    return SUCCESS;
}

//�жϷ������ȼ�
int Judge(Status flag, char c) {
    if (flag)
        switch (c) {               /*��ջ��Ԫ�ص����ȼ�*/
        case '+': return 3;
        case '-': return 3;
        case '*': return 5;
        case '/': return 5;
        case '(': return 1;
        case ')': return 6;
        }
    else
        switch (c) {               /*��ջ��Ԫ�ص����ȼ�*/
        case '+': return 2;
        case '-': return 2;
        case '*': return 4;
        case '/': return 4;
        case '(': return 6;
        case ')': return 1;
        }
    return 0;                      /*�������Ԫ�ط���0*/
}

//��׺���ʽ�ļ���
void arithmetic(ElemType E[]) {
    int i=0;
    ElemType a, b;
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));      /*�����������ֵ�ջ*/
    initLStack(s);
    while (E[i]) {
        if (E[i] >= '0' && E[i] <= '9')
            pushLStack(s, E[i]);
        else {
            popLStack(s, &a);
            popLStack(s, &b);
            if (E[i] == '+')
                pushLStack(s, (int)a + (int)b);
            if (E[i] == '-')
                pushLStack(s, (int)a - (int)b);
            if (E[i] == '*')
                pushLStack(s, (int)a * (int)b);
            if (E[i] == '/')
                pushLStack(s, (int)a / (int)b);
        }
        i++;
    }
    popLStack(s, &i);
    printf("%d\n\n", i);
    destroyLStack(s);
}