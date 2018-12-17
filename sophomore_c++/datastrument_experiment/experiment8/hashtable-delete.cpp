#include <stdio.h>
#include <string.h>

#define KEYLENGTH 15                   /* 关键词字符串的最大长度 */
typedef char ElementType[KEYLENGTH+1]; /* 关键词类型用字符串 */
typedef int Index;                     /* 散列地址类型 */
//typedef enum {false, true} bool;

typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode *HashTable; /* 散列表类型 */
struct TblNode {   /* 散列表结点定义 */
    int TableSize; /* 表的最大长度 */
    List Heads;    /* 指向链表头结点的数组 */
};

Index Hash( ElementType Key, int TableSize )
{
    return (Key[0]-'a')%TableSize;
}

HashTable BuildTable(); /* 裁判实现，细节不表 */
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













