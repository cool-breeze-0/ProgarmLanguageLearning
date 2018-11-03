//顺序表的实现

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

#include <iostream>
#include "malloc.h"
#include <stdlib.h>
using namespace std;

//顺序表结构体定义 
typedef struct
{
	ElemType *elem; //存储空间基址 
	int length; //顺序表的当前使用的长度【元素个数】 
	int listsize; //顺序表当前分配的长度【当前可容纳最多的元素个数】 
}Sqlist;

//顺序表创建
int InitSqlist(Sqlist &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType)); 
	//分配LIST_INIT_SIZE连续个存储单元，并将存储单元首地址(void *类型)强制转化为ElemType *类型返回给L.elem 
	if(!L.elem) exit(-1); //分配失败返回-1 
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 1;
}

//顺序表插入【在指定的第i(以Sqlist的开始元素为第0个)个位置插入元素e】
int Sqlist_Insert(Sqlist &L,int i,ElemType e)
{
	if(i<0 || i>L.length) return -1;
	if(L.length>=L.listsize)
	{
		ElemType *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType)); 
		//增加分配连续存储单元并将新连续存储单元首地址强制类型转化返回给L.newbase，返回给L.elem的话如果分配单元失败会使得原存储单元首地址丢失！ 
		if(!newbase) exit(-1);
		L.elem = newbase; 
		L.listsize += LISTINCREMENT;
	}
	ElemType *p = L.elem + L.length - 1;
	ElemType *q = L.elem + i;
	for(;p>=q;p--) *(p+1)=*(p);
	*(q) = e;
	++L.length;
	return 1;
} 
 
//顺序表删除 【在指定的第i(以Sqlist的开始元素为第0个)个位置删除元素用e返回删除元素】
int Sqlist_Delete(Sqlist &L,int i,ElemType &e)
{
 	if(i<0 || i>=L.length) return -1; //i值不合法，包含L.length值为0 
 	ElemType *p=L.elem + i;
 	e = *(p);
	ElemType *Llast=L.elem + L.length - 1;
	for(;p<Llast;++p) *p = *(p+1);
	--L.length;
	return 1;
} 

//在顺序表中查找第一个与e满足compare（）的元素的位序,有则返回位序，无则返回-1 
int Sqlist_Locate(Sqlist L,ElemType e,bool (*compare)(ElemType,ElemType))
{
	for(int i=0;i<L.length;i++)
  	{
  		if(compare(L.elem[i],e)) return i;
	}
	return -1;
}

//顺序表的合并【将非递减的顺序表La、Lb中的所有元素安非递减的顺序形成新的顺序表Lc】
int Sqlist_Marge(Sqlist La,Sqlist Lb,Sqlist &Lc) //Lc在此处可以不用初始化属性elem、length、listsize等 
{
	ElemType *p = La.elem, *q = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length; 
	Lc.elem = (ElemType *)malloc(Lc.listsize*sizeof(ElemType));
	ElemType *r = Lc.elem;
	if(!Lc.elem) exit(-1);
	while(p<=La.elem+La.length-1 && q<=Lb.elem+Lb.length-1)
	{
		if(*p<=*q) *r++=*p++;
		else *r++=*q++;
	}
	while(p<=La.elem+La.length-1) *r++ = *p++;
	while(q<=Lb.elem+Lb.length-1) *r++ = *q++;
	return 1;
}

//顺序表销毁
int Sqlist_Destory(Sqlist &L)
{
	free(L.elem);
	L.elem = NULL;
	return 1;
}

//顺序表清空
int Sqlist_Clear(Sqlist &L)
{
	L.length = 0;
	return 1;	
}

//顺序表判空
bool Sqlist_Empty(Sqlist L)
{
	return L.length==0;
}

//顺序表元素总个数 
int Sqlist_Length(Sqlist L)
{
	return L.length;
}

//获取位序为i的元素，返回到e中 
int Sqlist_GetElem(Sqlist L,int i,ElemType &e)
{
	if(i<0 || i>=L.length) return -1;
	e = L.elem[i];
	return 1;
}

// 返回cur_e元素的前驱
int Sqlist_PriorElem(Sqlist L,ElemType cur_e,ElemType &pre_e)
{
	for(int i=0;i<L.length;i++)
	{
		if(L.elem[i]==cur_e && i>=1)
		{
			pre_e = L.elem[i-1];
			return 1;
		}
	}
	return -1;
}

//返回cur_e的后继元素
int Sqlist_NextElem(Sqlist L,ElemType cur_e,ElemType &next_e)
{
	for(int i=0;i<L.length-1;i++)
	{
		if(L.elem[i]==cur_e)
		{
			next_e = L.elem[i+1];
			return 1;
		}
	}
	return -1;
}

//对表中的每一个数据元素调用visit（）函数
int Sqlist_Traverse(Sqlist L,void(*visit)(ElemType e)) //******************************
{
	if(L.length == 0) return -1;
	for(int i=0;i<L.length;i++)
	{
		visit(L.elem[i]);
	}
	return 1;
}

int main()
{
	cout<<"Sqlist has been achieved."<<endl;
	return 0; 
}
