#include <stdio.h>
#include <string.h>

#define KEYLENGTH 15                   /* �ؼ����ַ�������󳤶� */
typedef char ElementType[KEYLENGTH+1]; /* �ؼ����������ַ��� */
typedef int Index;                     /* ɢ�е�ַ���� */
//typedef enum {false, true} bool;

typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode *HashTable; /* ɢ�б����� */
struct TblNode {   /* ɢ�б��㶨�� */
    int TableSize; /* �����󳤶� */
    List Heads;    /* ָ������ͷ�������� */
};

Index Hash( ElementType Key, int TableSize )
{
    return (Key[0]-'a')%TableSize;
}

HashTable BuildTable(); /* ����ʵ�֣�ϸ�ڲ��� */
bool Delete( HashTable H, ElementType Key );

int main()
{
    HashTable H;
    ElementType Key;

    H = BuildTable(); 
    scanf("%s", Key);
    if (Delete(H, Key) == false)
        printf("ERROR: %s is not found\n", Key);
    if (Delete(H, Key) == true)
        printf("Are you kidding me?\n");
    return 0;
}

bool Delete( HashTable H, ElementType Key )
{
	int hashvalue=Hash(Key,H->TableSize);
	Position lead=(H->Heads+hashvalue)->Next,trail=H->Heads+hashvalue;
	for(;lead;trail=lead,lead=lead->Next)
	{
		if(!strcmp(lead->Data,Key))
		{
			trail->Next=lead->Next;
			printf("%s is deleted from list Heads[%d]",Key,hashvalue);
			return true;
		}
	 } 
	return false;
} 













