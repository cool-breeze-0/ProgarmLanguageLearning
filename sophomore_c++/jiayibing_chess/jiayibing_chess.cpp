//甲乙丙三人下棋，先甲与乙下然后获胜者与丙下，获胜者再与第一局失败者下，依次循环，直到有人连胜两局，设甲乙丙三人水平相同，获胜概率皆为0.5 
#include <iostream>
#include <stdlib.h>  
#include <time.h>  
void analog(int);
using namespace std;
int main()
{
	int ana_time;
	cout<<"please input moni_time:";
	cin>>ana_time;
	analog(ana_time); 
	return 0;
 } 
 void analog(int ana_time) 
 {
 	int jia=0,yi=0,bing=0;	
	srand((unsigned)time(NULL));
	
 	for(int i=0;i<ana_time;i++)
	{
		int p=0,q=0;
		float rate0=float(rand()%1000)/float(1000);
		if(rate0>0.5)
		{
			q=1;
		}
		else
		{
			q=2;
		}
		float rate1=float(rand()%1000)/float(1000);
		if(rate1>0.5)
		{
			p=q;
		}
		else
		{
			p=q;
			q=3;
		}
		while(p!=q) 
		{
			float rate=float(rand()%1000)/float(1000);
			if(rate>0.5)
			{
				p=q;		
			}
			else
			{
				int t=p;
				p=q;
				q=6-p-t;
			}
		}
		if(p==1)
		{
			jia += 1;
		}
		else if(p==2)
		{
			yi += 1;
		}
		else
		{
			bing += 1;
		}
	} 
	cout<<"jia win:"<<float(jia)/float(ana_time)<<endl;
	cout<<"yi win:"<<float(yi)/float(ana_time)<<endl;
	cout<<"bing win:"<<float(bing)/float(ana_time)<<endl;
 }
