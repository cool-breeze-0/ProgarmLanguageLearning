//链表的实现

#define ElemType int

#include<iostream>
#include<stdlib.h>
using namespace std;

//链表结点结构体定义 
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList; //用typedef定义LNode为结构体LNode类型、Linklist为结构体LNode指针类型！

//初始化链表，使用头插法生成链表 ，头结点为空 
void InitList_LinkList(LinkList L,int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	/*如果存在变量p，指向a, 即p = &a, 这时可以用p->b来使用成员b。即，->操作符是用于带成
	员的类型对应指针上，用来提取成员变量或函数用的。p->b等同于(*p).b。对于任意的对象a，写作(&a)->b也是可以的，不过很少有这样写。*/
	L->next=NULL;
	for(int i=0;i<n;i++)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		cin>>p->data; //scanf(&p->data)????
		p->next=L->next;
		L->next=p;
	}
}

//链表的插入，头结点->next为第0号元素
int LinkList_Insert(LinkList &L,int i,ElemType e)
{
	LinkList p=L;
	int j=0;
	for(;p && i>j;j++) p=p->next; //p最后应指向第 i-1位元素 
	if(!p || i<0) return -1;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next=p->next;
	p->next=s;
	return 1;
}

//链表的删除
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

//获取元素
int LinkList_GetElem(LinkList L,int i,ElemType &e)
{
	LinkList p=L;
	int j=0;
	for(;p && j<=i;j++) p = p->next;
	if(!p || i<0) return -1;
	e = p->data;
	return 1;
}

//销毁链表使用free函数，用法：void free(void *ptr);
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

//清空链表 
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

//链表判空
bool LinkList_Empty(LinkList L)
{
	return L->next == NULL;
}

//链表求长
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


