//数据结构实验第二周数据结构实验1题二：计算前缀表达式的值

#include<iostream>

using namespace std;

void function(char*,int);
void format_control(float);

int main()
{
	char exp[61];
	cin.getline(exp,61);
	int i=0;
	for(;exp[i]!='\0';i++);
	if(i>30)
	{
		cout<<"ERROR";
		return 0;
	}
	function(exp,i);
	return 0;
}

void function(char *exp,int all)
{
	float elem[30];
	int elemi=0;
	for(int i=all;i>=0;i--)
	{
		if(exp[i]=='\0' || exp[i]==' ') continue;
		if(exp[i]=='+') 
		{
			if(elemi-2<0 || (i>=1 && exp[i-1]!=' ' ))
			{
				cout<<"ERROR"<<endl;
				return; 
			}
			elem[elemi-2] = elem[elemi-1]+elem[elemi-2];
			elemi-=1;
		}
		else if(exp[i]=='-')
		{
			if(elemi-2<0 || (i>=1 && exp[i-1]!=' ' ))
			{
				cout<<"ERROR"<<endl;
				return; 
			}
			elem[elemi-2] = elem[elemi-1]-elem[elemi-2];
			elemi-=1;
		}
		else if(exp[i]=='*')
		{
			if(elemi-2<0 || (i>=1 && exp[i-1]!=' ' ))
			{
				cout<<"ERROR"<<endl;
				return; 
			}
			elem[elemi-2] = elem[elemi-1]*elem[elemi-2];
			elemi-=1;
		}
		else if(exp[i]=='/')
		{
			if(elemi-2<0 || (i>=1 && exp[i-1]!=' ' ))
			{
				cout<<"ERROR"<<endl;
				return; 
			}
			elem[elemi-2] = elem[elemi-1]/elem[elemi-2];
			elemi-=1;
		}
		else if(exp[i]>47 && exp[i]<58)
		{
			if(i>0 && exp[i-1]>47 && exp[i-1]<58) continue;
			else
			{
				if(i>=1 && exp[i-1]!=' ' )
				{
					cout<<"ERROR"<<endl;
					return;
				}
				elem[elemi]=0.0;
				for(int j=i;exp[j]!=' ' && exp[j]!='\0';j++)
				{
					elem[elemi]=float(elem[elemi]*10+exp[j]-48);
				}
				elemi+=1;
			} 
		}
		else
		{
			cout<<"ERROR"<<endl;
			return;
		}
	}
	if(elemi!=1)
	{
		cout<<"ERROR"<<endl;
		return;
	}
	format_control(elem[0]);
}

void format_control(float num)
{
	int first,second;
	first = (int)((num-int(num))*10);
	second =(int)((num*10-int(num*10))*10);
	if(second>=5)
	{
		cout<<int(num)<<'.'<<first+1;
	}
	else
	{
		cout<<int(num)<<'.'<<first;
	}
}
