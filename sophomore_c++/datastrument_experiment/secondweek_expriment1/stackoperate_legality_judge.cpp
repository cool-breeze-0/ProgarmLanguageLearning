//数据结构实验第二周数据结构实验1题一：判断堆栈的操作合法性

#include<iostream>

using namespace std;

int function(int);

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) function(m);
	return 0;
}

int function(int capacity)
{
	char row[101];
	cin>>row;
	int s=0,x=0;
	for(int i=0;row[i]!='\0';i++)
	{
		if(row[i]=='S') s+=1;
		else x+=1;
		if(s-x<0 || s-x>capacity)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(s-x != 0) 
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}
