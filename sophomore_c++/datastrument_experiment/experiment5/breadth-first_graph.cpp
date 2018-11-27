#include <stdio.h>
//typedef enum {false, true} bool;
#define MaxVertexNum 10   /* ��󶥵�����Ϊ10 */
typedef int Vertex;       /* �ö����±��ʾ����,Ϊ���� */
/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* �ڽӵ��±� */
    PtrToAdjVNode Next; /* ָ����һ���ڽӵ��ָ�� */
};
/* �����ͷ���Ķ��� */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* �߱�ͷָ�� */
} AdjList[MaxVertexNum];     /* AdjList���ڽӱ����� */
/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* ������ */
    int Ne;     /* ����   */
    AdjList G;  /* �ڽӱ� */
};
typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */
bool Visited[MaxVertexNum]; /* ����ķ��ʱ�� */
LGraph CreateGraph(); /* ����ͼ���ҽ�Visited��ʼ��Ϊfalse������ʵ�֣�ϸ�ڲ��� */
void Visit( Vertex V )
{
    printf(" %d", V);
}
void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) );
int main()
{
    LGraph G;
    Vertex S;

    G = CreateGraph();
    scanf("%d", &S);
    printf("BFS from %d:", S);
    BFS(G, S, Visit);

    return 0;
}
#include<stdlib.h>
void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
	int duilie[100];
	Visit(S);		
	Visited[S]=true;
	int first=0,rear=0;
	duilie[first]=S;
	while(rear-first>=0)
	{
		int p=duilie[first++];
		PtrToAdjVNode q=Graph->G[p].FirstEdge;
		while(q)
		{
			if(!Visited[q->AdjV])
			{
				Visit(q->AdjV);		//��visit�ٷ�����У����������ڽ����S·������ͬ�ĵ��ظ�������е������˳�򽻻��ͻᣡȻ�������ѭ�� ������ 
				Visited[q->AdjV]=true;
				duilie[++rear]=q->AdjV;
			}
			q=q->Next;
		}
	}
}
