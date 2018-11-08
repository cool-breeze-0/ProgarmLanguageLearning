#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct TNode{
  char data;
  struct TNode *left;
  struct TNode *right;
}TNode,*Position;

void function(char a[]);
void Tra1(Position BT);
void Tra1(Position BT)
{
  if(BT)
  {
    Tra1(BT->left);
    cout<<BT->data;
    Tra1(BT->right);
  }
}
void function(char a[])
{
  Position chu=(Position)malloc(sizeof(TNode));
  chu->data='\0';
  chu->left=chu->right=NULL;
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
  TNode *stack[100];
  stack[1]=T;
  stach[0]=chu;
  int top=2,p=0;
  for(int i=1;a[i]=='#'||(a[i]>=65&&a[i]<=90);i++)
  {
    if(a[i]=='#')
    {
      if(p==0) p++;
      if(p==1)
      {
        while((stack[top-2]->right)==stack[top-1]) top--;
        //if(stack[top-2].right==stack[top-1]) top--;
        top--;
        num++;
      }
    }
    else
    {
      Position q=(Position)malloc(sizeof(TNode));
      q->data=a[i];
      q->left=q->right=NULL;
      cout<<1;
	  if(p==0)
      {
        stack[top-1]->left=q;
        stack[top]=q;
        top++;
      }
      else if(p==1)
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
  char a[10000];
  cin>>a;
  function(a);
}
