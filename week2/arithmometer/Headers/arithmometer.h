#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef char ElemType;

//链栈结点结构
typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

//链栈头结点
typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
Status initLStack(LinkStack* s);//初始化栈
Status isEmptyLStack(LinkStack* s);//判断栈是否为空
Status getTopLStack(LinkStack* s, ElemType* e);//得到栈顶元素
Status destroyLStack(LinkStack* s);//销毁栈
Status pushLStack(LinkStack* s, ElemType data);//入栈
Status popLStack(LinkStack* s, ElemType* data);//出栈


//中缀表达式转换为后缀表达式并计算
Status Transformmid(ElemType s[], ElemType (*E)[]);
int Judge(Status flag, char m);
void arithmetic(ElemType E[]);



#endif
