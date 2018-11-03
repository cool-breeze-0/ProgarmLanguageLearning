#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n>100000) return 0;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int p=0,q=1,init=0,length=1;
	for(int j=1;j<n;j++)
	{
		if(a[j]>a[j-1]) q+=1;
		else
		{
			if(q>length)
			{
				init=p;
				length=q;	
			}
			p=j;
			q=1;
		}
	}
	for(int k=0;k<length;k++)
	{
		if(k==length-1) 
		{
			cout<<a[init+k];
		}
		else 
		{
			cout<<a[init+k]<<' ';
		}
	}
	return 0;
}
