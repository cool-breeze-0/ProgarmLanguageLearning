//�����ʵ��

#define ElemType int

#include<iostream>
#include<stdlib.h>
using namespace std;

//������ṹ�嶨�� 
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList; //��typedef����LNodeΪ�ṹ��LNode���͡�LinklistΪ�ṹ��LNodeָ�����ͣ�

//��ʼ������ʹ��ͷ�巨�������� ��ͷ���Ϊ�� 
void InitList_LinkList(LinkList L,int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	/*������ڱ���p��ָ��a, ��p = &a, ��ʱ������p->b��ʹ�ó�Աb������->�����������ڴ���
	Ա�����Ͷ�Ӧָ���ϣ�������ȡ��Ա���������õġ�p->b��ͬ��(*p).b����������Ķ���a��д��(&a)->bҲ�ǿ��Եģ���������������д��*/
	L->next=NULL;
	for(int i=0;i<n;i++)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		cin>>p->data; //scanf(&p->data)????
		p->next=L->next;
		L->next=p;
	}
}

//����Ĳ��룬ͷ���->nextΪ��0��Ԫ��
int LinkList_Insert(LinkList &L,int i,ElemType e)
{
	LinkList p=L;
	int j=0;
	for(;p && i>j;j++) p=p->next; //p���Ӧָ��� i-1λԪ�� 
	if(!p || i<0) return -1;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next=p->next;
	p->next=s;
	return 1;
}

//�����ɾ��
int LinkList_Delete(LinkList &L,int i,ElemType e)
{
	LinkList p = L;
	int j=0;
	for(;p->next && i>j;j++) p=p->next;
	if(!(p->next) || i<0) return -1;
	LinkList q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return 1;
}

//��ȡԪ��
int LinkList_GetElem(LinkList L,int i,ElemType &e)
{
	LinkList p=L;
	int j=0;
	for(;p && j<=i;j++) p = p->next;
	if(!p || i<0) return -1;
	e = p->data;
	return 1;
}

//��������ʹ��free�������÷���void free(void *ptr);
int LinkList_Destroy(LinkList &L)
{
	if(L) return -1;
	while(L)
	{
		LinkList p=L->next;
		free(L);
		L = p;
	}
	return 1;
}

//������� 
int LinkList_ClearList(LinkList &L)
{
	LinkList p=L->next;
	L->next = NULL;
	while(p)
	{
		LinkList q=p->next;
		free(p);
		p=q; 
	} 
	return 1;
}

//�����п�
bool LinkList_Empty(LinkList L)
{
	return L->next == NULL;
}

//������
int LinkList_Length(LinkList L)
{
	LinkList p=L->next;
	int j=0;
	for(;p;j++) p=p->next;
	return j;
}

int main()
{
	cout<<"LinkList has been achieved."<<endl;
	return 0; 
}


