//顺序队列的实现

#define QElemType int 
#define MAXQSIZE 100

#include <iostream>
#include <stdlib.h>
using namespace std;

//顺序队列结构体
typedef struct
{
	QElemType *base;
	int front;
	int rear;
 } SqQueue;
 
//初始化顺序队列
int InitSqQueue(SqQueue &Q)
{
	Q.base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q.base) return -1;
	Q.front = Q.rear = 0;
	return 1; 
}

//顺序队列插入
int SqQueue_Insert(SqQueue &Q,QElemType e)
{
	if((Q.rear+1)%MAXQSIZE == Q.front) return -1;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return 1;
 } 

//顺序队列删除
int SqQueue_Delete(SqQueue &Q,QElemType &e)
{
	if(Q.front == Q.rear) return -1;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return 1;
 } 

//顺序队列销毁
int SqQueue_Destroy(SqQueue &Q)
{
	free(Q.base);
	Q.base = NULL;
	return 1;
 } 

//顺序队列清空
int SqQueue_ClearQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;
	return 1;
 } 

//顺序队列判空
bool SqQueue_Empty(SqQueue Q)
{
	return Q.front == Q.rear;
 } 

//顺序队列求长
int SqQueue_Length(SqQueue Q)
{
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
 } 
 
//顺序队列获取队首元素
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


