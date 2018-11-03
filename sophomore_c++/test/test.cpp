//test.cpp
#include<iostream>
using namespace std;
int main()
{
	int exit;
	cout<<"hello world"<<endl;
	char i[3];
	cin>>i;
	if(i == "abc") cout<<465;
	cout<<"please input -1 and enter to exit:";
	cin>>exit;
	while(exit != -1)
	{
		cout<<"please input -1 and enter to exit£º";
		cin>>exit; 
	}
	return 0;
 } 
 
