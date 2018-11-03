//˳��ջ��ʵ��

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define SElemType int

#include <iostream>
#include "malloc.h"
#include <stdlib.h>
using namespace std;

//˳��ջ�ṹ��
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//˳��ջ��ʼ��
int InitSqStack(SqStack &S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) return -1;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}

//˳��ջ����ջ
int SqStack_Push(SqStack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return -1;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return 1;
}

//˳��ջ�ĳ�ջ
int SqStack_Pop(SqStack &S,SElemType &e)
{
	if(S.top == S.base) return -1;
	e = *S.top--;
	return 1;
}

//ȡ��˳��ջ��ջ��Ԫ��
int SqStack_GetTop(SqStack S,SElemType &e)
{
	if(S.top == S.base) return -1;
	e = *(S.top - 1);
	return 1;
}

//����˳��ջ 
int SqStack_Destroy(SqStack &S)
{
	free(S.base);
	S.base = NULL;
	return 1;
}

//���˳��ջ
int SqStack_ClearStack(SqStack &S)
{
	S.top = S.base;
	return 1;
}

//˳��ջ�п�
bool SqStack_Empty(SqStack S)
{
	return S.top == S.base;
}

//˳��ջ��Ԫ�ظ���
int SqStack_Length(SqStack S)
{
	return S.top - S.base;
}

int main()
{
	cout<<"SqStack has been achieved."<<endl;
	return 0; 
}
