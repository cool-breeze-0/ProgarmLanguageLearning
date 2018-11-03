//˳����ʵ��

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

#include <iostream>
#include "malloc.h"
#include <stdlib.h>
using namespace std;

//˳���ṹ�嶨�� 
typedef struct
{
	ElemType *elem; //�洢�ռ��ַ 
	int length; //˳���ĵ�ǰʹ�õĳ��ȡ�Ԫ�ظ����� 
	int listsize; //˳���ǰ����ĳ��ȡ���ǰ����������Ԫ�ظ����� 
}Sqlist;

//˳�����
int InitSqlist(Sqlist &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType)); 
	//����LIST_INIT_SIZE�������洢��Ԫ�������洢��Ԫ�׵�ַ(void *����)ǿ��ת��ΪElemType *���ͷ��ظ�L.elem 
	if(!L.elem) exit(-1); //����ʧ�ܷ���-1 
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 1;
}

//˳�����롾��ָ���ĵ�i(��Sqlist�Ŀ�ʼԪ��Ϊ��0��)��λ�ò���Ԫ��e��
int Sqlist_Insert(Sqlist &L,int i,ElemType e)
{
	if(i<0 || i>L.length) return -1;
	if(L.length>=L.listsize)
	{
		ElemType *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType)); 
		//���ӷ��������洢��Ԫ�����������洢��Ԫ�׵�ַǿ������ת�����ظ�L.newbase�����ظ�L.elem�Ļ�������䵥Ԫʧ�ܻ�ʹ��ԭ�洢��Ԫ�׵�ַ��ʧ�� 
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
 
//˳���ɾ�� ����ָ���ĵ�i(��Sqlist�Ŀ�ʼԪ��Ϊ��0��)��λ��ɾ��Ԫ����e����ɾ��Ԫ�ء�
int Sqlist_Delete(Sqlist &L,int i,ElemType &e)
{
 	if(i<0 || i>=L.length) return -1; //iֵ���Ϸ�������L.lengthֵΪ0 
 	ElemType *p=L.elem + i;
 	e = *(p);
	ElemType *Llast=L.elem + L.length - 1;
	for(;p<Llast;++p) *p = *(p+1);
	--L.length;
	return 1;
} 

//��˳����в��ҵ�һ����e����compare������Ԫ�ص�λ��,���򷵻�λ�����򷵻�-1 
int Sqlist_Locate(Sqlist L,ElemType e,bool (*compare)(ElemType,ElemType))
{
	for(int i=0;i<L.length;i++)
  	{
  		if(compare(L.elem[i],e)) return i;
	}
	return -1;
}

//˳���ĺϲ������ǵݼ���˳���La��Lb�е�����Ԫ�ذ��ǵݼ���˳���γ��µ�˳���Lc��
int Sqlist_Marge(Sqlist La,Sqlist Lb,Sqlist &Lc) //Lc�ڴ˴����Բ��ó�ʼ������elem��length��listsize�� 
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

//˳�������
int Sqlist_Destory(Sqlist &L)
{
	free(L.elem);
	L.elem = NULL;
	return 1;
}

//˳������
int Sqlist_Clear(Sqlist &L)
{
	L.length = 0;
	return 1;	
}

//˳����п�
bool Sqlist_Empty(Sqlist L)
{
	return L.length==0;
}

//˳���Ԫ���ܸ��� 
int Sqlist_Length(Sqlist L)
{
	return L.length;
}

//��ȡλ��Ϊi��Ԫ�أ����ص�e�� 
int Sqlist_GetElem(Sqlist L,int i,ElemType &e)
{
	if(i<0 || i>=L.length) return -1;
	e = L.elem[i];
	return 1;
}

// ����cur_eԪ�ص�ǰ��
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

//����cur_e�ĺ��Ԫ��
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

//�Ա��е�ÿһ������Ԫ�ص���visit��������
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
