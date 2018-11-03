//求4个整数的和与平均值,平均值保留一位小数，四舍五入 
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<"Sum = "<<a+b+c+d<<"; Average = ";
	float average = (a+b+c+d)/4.0;
	int first,second;
	first = (int)((average-int(average))*10);
	second =(int)((average*10-int(average*10))*10);
	if(second>=5)
	{
		cout<<int(average)<<'.'<<first+1;
	}
	else
	{
		cout<<int(average)<<'.'<<first;
	}
	return 0;
}
