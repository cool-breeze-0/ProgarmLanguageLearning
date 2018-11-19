#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct {
	int weight;
	int lchird,rchild,judge;
}TNode,*HT;

void create(HT &T,int *length,int n)
{
	if(n<=1) return;
	T=(HT)malloc((2*n-1)*sizeof(TNode));
	HT p=T;
	for(int i=0;i<n;i++)
	{
		p->weight=length[i];
		p->lchird=p->rchild=-1;
		p->judge=0;
		p++;
	}
	for(int i=n;i<2*n-1;i++)
	{
		int x=-1,y=-1;
		for(int j=0;j<i;j++)
		{
			if(T[j].judge==0)
			{
				if(x==-1) x=j;
				else
				{
					y=j;
					break;
				}
			}
		}
		for(int j=y+1;j<i;j++)
		{
			if((T[j].weight<=T[x].weight || T[j].weight<=T[y].weight)&&(T[j].judge==0))
			{
				if(T[x].weight<T[y].weight) y=j;
				else x=j;
			}
		}
		T[i].judge=0;
		T[i].lchird=x;
		T[i].rchild=y;
		T[i].weight=T[x].weight+T[y].weight;
		T[x].judge=T[y].judge=1;
	}
}

int bianli(HT T,int n)
{
	int min = 0;
	for(int i=n;i<2*n-1;i++) min+=T[i].weight;
	return min;
}

int main()
{
	HT T;
	int n;
	cin>>n;
	int length[n];
	for(int i=0;i<n;i++)
	{
		cin>>length[i];
	}
	create(T,length,n);
	int min=bianli(T,n);
	cout<<min<<endl;
	return 0;
}
