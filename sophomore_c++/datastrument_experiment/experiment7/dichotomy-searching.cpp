#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}
Position BinarySearch( List L, ElementType X )
{
	if(L->Last)
	{
		int low=1,high=L->Last;
		int mid=(low+high)/2;
		while(low<=high)
		{
			if(X>L->Data[mid])
			{
				low=mid+1;
				mid=(low+high)/2;
			}
			else if(X==L->Data[mid]) return mid;
			else
			{
				high=mid-1;
				mid=(low+high)/2;
			}
		}
		return NotFound; 
	}
	return NotFound;
} 

