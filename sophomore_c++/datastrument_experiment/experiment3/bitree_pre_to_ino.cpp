#include <iostream> 
#include <stdlib.h>
using namespace std;
typedef struct TNode{
  char data;
  struct TNode *left;
  struct TNode *right;
}TNode,*Position;
void Tra1(Position BT)
{
  if(BT)
  {
    Tra1(BT->left);
    cout<<BT->data;
    Tra1(BT->right);
  }
}
void function(char *a)
{
  Position T=(Position)malloc(sizeof(TNode));
  if(a[0]!='#')
  {
    T->data=a[0];
    T->left=T->right=NULL;
  }
  else 
  {
    cout<<endl;
    cout<<0<<endl;
  }
  int num=0;
  TNode *stack[10];
  stack[1]=T;
  stack[0]=(Position)malloc(sizeof(TNode)); //stack[0]一定要有初值指向一个TNode结构体,不然后面调用到stack[0]时会蓝屏闪退！！！ 
  int top=2,p=0;
  for(int i=1;a[i]!='\0';i++)
  {
	if(a[i]=='#')
    {
      if(p==0)
	  {
	  	p++;
	   } 
      else
      {
        if(stack[top-1]->left==NULL) num++;
		while(stack[top-2]->right==stack[top-1]) top--;
        top--;
      }
    }
    else
    {
      Position q=(Position)malloc(sizeof(TNode));
      q->data=a[i];
      q->left=q->right=NULL;
	  if(p==0)
      {
		stack[top-1]->left=q;
        stack[top]=q;
        top++;
      }
      else
      {
        stack[top-1]->right=q;
        stack[top]=q;
        top++;
        p=0;
      }
    }
  }
  Tra1(T);
  cout<<endl;
  cout<<num<<endl;
}
int main()
{
  char a[100];
  cin>>a;
  function(a);
}
