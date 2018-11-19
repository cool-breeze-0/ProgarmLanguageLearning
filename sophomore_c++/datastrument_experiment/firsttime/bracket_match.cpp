//À¨ºÅºÍ×¢ÊÍ·ûÆ¥ÅäÎÊÌâ
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char sqstack[200];
	int top = 0;
	char pro[100];
	cin.getline(pro,100);
	while(pro != '.')
	{
		for(int i=0;i<strlen(pro);i++)
		{
			if(pro[i]=='(')
			{
				sqstack[top]='(';
				top += 1;
			}
			else if(pro[i]=='[')
			{
				sqstack[top]='[';
				top +=1;
			}
			else if(pro[i]=='{')
			{
				sqstack[top]='{';
				top +=1;
			} 
			else if(pro[i]=='/' && pro[i+1]=='*')
			{
				sqstack[top++]='/';
				sqstack[top++]='*';
			}
			if(pro[i]==')')
			{
				if(sqstack[top]!='(')
			/*	
				top -= 1;
			}
			else if(pro[i]=='[')
			{
				sqstack[top]='[';
				top +=1;
			}
			else if(pro[i]=='{')
			{
				sqstack[top]='{';
				top +=1;
			} 
			else if(pro[i]=='/' && pro[i+1]=='*')
			{
				sqstack[top++]='/';
				sqstack[top++]='*';
			}*/
			
		}
	 } 
	cout<<pro;
	return 0;
 } 
