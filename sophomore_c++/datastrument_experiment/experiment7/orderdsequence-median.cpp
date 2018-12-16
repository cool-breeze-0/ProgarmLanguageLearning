#include<iostream>

using namespace std;

int function(int *a,int *b,int N);
int main()
{
	int N;
	cin>>N;
	int a[N],b[N];
	for(int i=0;i<N;i++) cin>>a[i];
	for(int i=0;i<N;i++) cin>>b[i];
	cout<<function(a,b,N);
 } 

int function(int *a,int *b,int N)
{
	int p=0,q=0;
	while(p<N && q<N)
	{
		if(p+q==N-1)
		{
			if(a[p]<b[q]) return a[p];
			else return b[q];
		}
		if(a[p]<=b[q]) p++;
		else q++;
	}
}
