#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct node 
{	
	char data;			//数据元素
	struct node *lchild;	//指向左孩子节点
	struct node *rchild;	//指向右孩子节点
} BTNode;

BTNode *xh(char *a,char *b)
{
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]==b[strlen(b)-1])
		{
			BTNode *p=(BTNode*)malloc(sizeof(BTNode));
			p->data=a[i];
			p->lchild=p->rchild=NULL;
			if(i!=0)
			{
				char a1[i+1];
				for(int j=0;j<i;j++)
				{
					a1[j]=a[j];
				}
				a1[i]='\0';
				char b1[i+1];
				for(int j=0;j<i;j++)
				{
					b1[j]=b[j];
				}
				b1[i]='\0';
				p->lchild=xh(a1,b1);
			}
			if(i!=strlen(a)-1)
			{
				char a2[strlen(a)-i];
				for(int j=0;j<strlen(a)-i;j++)
				{
					a2[j]=a[i+j+1];
				}
				char b2[strlen(b)-i];
				for(int j=0;j<strlen(b)-i-1;j++)
				{
					b2[j]=b[i+j];
				}
				b2[strlen(b)-i-1]='\0';
				p->rchild=xh(a2,b2);
			}
			return p;
		}
	}
	return NULL;
}

void dis(BTNode *b)
{
	if(b)
	{
		cout<<b->data;
		if(b->lchild || b->rchild) 
		{
			cout<<'(';
			dis(b->lchild);
			cout<<',';
			dis(b->rchild);
			cout<<')';
		}
	}
}

int main()
{
	char a[100],b[100];
	cout<<"input aftorder_traverse:";
	cin>>b;
	cout<<"input inorder_traverse:";
	cin>>a;
	BTNode *bt=xh(a,b);
	dis(bt);
	cout<<endl;
}
