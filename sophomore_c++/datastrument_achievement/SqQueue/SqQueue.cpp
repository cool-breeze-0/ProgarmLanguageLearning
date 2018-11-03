//˳����е�ʵ��

#define QElemType int 
#define MAXQSIZE 100

#include <iostream>
#include <stdlib.h>
using namespace std;

//˳����нṹ��
typedef struct
{
	QElemType *base;
	int front;
	int rear;
 } SqQueue;
 
//��ʼ��˳�����
int InitSqQueue(SqQueue &Q)
{
	Q.base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q.base) return -1;
	Q.front = Q.rear = 0;
	return 1; 
}

//˳����в���
int SqQueue_Insert(SqQueue &Q,QElemType e)
{
	if((Q.rear+1)%MAXQSIZE == Q.front) return -1;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return 1;
 } 

//˳�����ɾ��
int SqQueue_Delete(SqQueue &Q,QElemType &e)
{
	if(Q.front == Q.rear) return -1;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return 1;
 } 

//˳���������
int SqQueue_Destroy(SqQueue &Q)
{
	free(Q.base);
	Q.base = NULL;
	return 1;
 } 

//˳��������
int SqQueue_ClearQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;
	return 1;
 } 

//˳������п�
bool SqQueue_Empty(SqQueue Q)
{
	return Q.front == Q.rear;
 } 

//˳�������
int SqQueue_Length(SqQueue Q)
{
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
 } 
 
//˳����л�ȡ����Ԫ��
int SqQueue_GetHead(SqQueue Q,QElemType &e)
{
	if(Q.front == Q.rear) return -1;
	e = Q.base[Q.front];
	return 1; 
 } 

int main()
{
	cout<<"SqQueue has been achieved."<<endl;
	return 0;
}


