//��4�������ĺ���ƽ��ֵ,ƽ��ֵ����һλС������������ 
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
