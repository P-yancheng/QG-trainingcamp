#include<stdio.h>
#include"Stack.h"

//中缀表达式转换为后缀表达式
Status Transformmid (ElemType m[],ElemType (*E)[]) {
    int i=0,j=0;
    LinkStack* s= (LinkStack*)malloc(sizeof(LinkStack));      /*用来贮存符号的栈*/
    initLStack(s);
    ElemType e,d;                                             /*记录栈顶元素和取出栈顶元素*/
    Status J,flag=0;                                          /*判断用枚举变量*/
    for (i = 0;m[i] != '\0';i++) {                            /*遍历中缀表达式的每个元素*/
        if (m[i] >= '0' && m[i] <= '9') {
            (*E)[j++] = m[i];                                 /*数字直接存进数组*/
        }
        else if (Judge(SUCCESS, m[i]) != 0) {
            if (isEmptyLStack(s))
                pushLStack(s, m[i]);                          /*若栈空则直接入栈*/
            else {
                getTopLStack(s, &e);
                if (Judge(SUCCESS, e) > Judge(ERROR, m[i])) {              /*里面优先级大时，将优先级大的符号逐个出栈*/
                    while (Judge(SUCCESS, e) > Judge(ERROR, m[i])) {
                        popLStack(s, &d);
                        (*E)[j++] = d;
                        if (isEmptyLStack(s)) {                            /*直到空栈为止，并将此符号入栈*/
                            pushLStack(s, m[i]);
                            break;
                        }
                        getTopLStack(s, &e);
                        if (Judge(SUCCESS, e) == Judge(ERROR, m[i])) {     /*右括号遇到左括号时，直接弹出不赋值*/
                            popLStack(s, &d);
                            break;
                        }
                    }
                }
                else if (Judge(SUCCESS, e) < Judge(ERROR, m[i])) {
                    pushLStack(s, m[i]);
                    e = m[i];
                }
                else                                          /*优先级相等证明是两个对此括号，则直接出栈且不存入表达式*/
                    popLStack(s, &d);
            }
        }
        else continue;
    }
    while (!isEmptyLStack(s)) {                               /*将栈中剩下的元素弹栈*/
        popLStack(s, &d);
        (*E)[j++] = d;
    }
    (*E)[j] = '\0';                                           /*给后缀表达式数组添加结束符*/
    destroyLStack(s);
    if (!(*E))
        return ERROR;
    return SUCCESS;
}

//判断符号优先级
int Judge(Status flag, char c) {
    if (flag)
        switch (c) {               /*在栈内元素的优先级*/
        case '+': return 3;
        case '-': return 3;
        case '*': return 5;
        case '/': return 5;
        case '(': return 1;
        case ')': return 6;
        }
    else
        switch (c) {               /*在栈外元素的优先级*/
        case '+': return 2;
        case '-': return 2;
        case '*': return 4;
        case '/': return 4;
        case '(': return 6;
        case ')': return 1;
        }
    return 0;                      /*输入错误元素返回0*/
}

//后缀表达式的计算
void arithmetic(ElemType E[]) {
    int i=0;
    ElemType a, b;
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));      /*用来贮存数字的栈*/
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