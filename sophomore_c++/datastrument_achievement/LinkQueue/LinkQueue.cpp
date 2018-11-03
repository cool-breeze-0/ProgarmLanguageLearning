//��ʽ���е�ʵ��

#define QElemType int

#include <iostream>
#include <stdlib.h>
using namespace std;

//���ṹ��
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

//��ʽ���нṹ��
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//��ʼ����ʽ���� 
int InitLinkQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) return -1;
	Q.front->next = NULL;
	return 1;
 } 

//��ʽ���еĲ���
int LinkQueue_Insert(LinkQueue &Q,QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) return -1;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 1;
 } 

//��ʽ���е�ɾ��
int LinkQueue_Delete(LinkQueue &Q,QElemType &e)
{
	if(Q.front == Q.rear) return -1;
	QueuePtr p = Q.front->next;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear = Q.front;
	e = p->data;
	free(p);
	return 1;
 } 

//��ʽ��������
int LinkQueue_Destroy(LinkQueue &Q)
{
	while(Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return 1;
 } 

//��ʽ�������
int LinkQueue_ClearQueue(LinkQueue &Q)
{
	QueuePtr p = Q.front->next;
	while(p)
	{
		Q.front->next=p->next;
		free(p);
		p=Q.front->next;
	}
	Q.rear = Q.front;
	return 1;
 } 

//��ʽ�����п�
bool LinkQueue_Empty(LinkQueue Q)
{
	return Q.front == Q.rear;
 } 

//��ʽ������
int LinkQueue_Length(LinkQueue Q)
{
	QueuePtr p = Q.front;
	int j=0;
	for(;p!=Q.rear;j++) p=p->next;
	return j;
 } 

//��ʽ����ȡ����Ԫ��
int LinkQueue_GetHead(LinkQueue Q,QElemType &e)
{
	if(Q.front == Q.rear) return -1;
	e=Q.front->next->data;
	return 1;
 } 

int main()
{
	cout<<"LinkQueue has been achieved."<<endl;
	return 0;
}


