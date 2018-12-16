//判断图中是否能进行拓扑排序 
#include <stdio.h>
#include <stdlib.h>

//typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;


LGraph ReadG(); /* details omitted */
/**
LGraph ReadG()
{
	LGraph G;
	G->Ne=7;
	G->Nv=5;
	G->G[0].FirstEdge->AdjV=NULL;
	G->G[1].FirstEdge->AdjV=;
}
*/

bool TopSort( LGraph Graph, Vertex TopOrder[] );

int main()
{
    int i;
    Vertex TopOrder[MaxVertexNum];
    LGraph G = ReadG();

    if ( TopSort(G, TopOrder)==true )
        for ( i=0; i<G->Nv; i++ )
            printf("%d ", TopOrder[i]);
    else
        printf("ERROR");
    printf("\n");

    return 0;
}
/*
int locate(LGraph Graph,int *b)
{
	int a[Graph->Nv];
	for(int i=0;i<Graph->Nv;i++) a[i]=b[i];
	for(int i=0;i<Graph->Nv;i++)
	{
		PtrToAdjVNode p=Graph->G[i].FirstEdge;
		while(p)
		{
			a[p->AdjV]=1;
			p=p->Next;
		}
	}
	for(int j=0;j<Graph->Nv;j++)
	{
		if(!a[j]) return j;
	}
	return -1;
}

bool TopSort( LGraph Graph, Vertex TopOrder[] )
{
	int top=0;
	int b[Graph->Nv];
	for(int i=0;i<Graph->Nv;i++) b[i]=0;
	int j=locate(Graph,b);
	while(j!=-1)
	{
		
		TopOrder[top++]=j;
		Graph->G[j].FirstEdge=NULL;
		b[j]=1;
		j=locate(Graph,b);
	}
	for(int i=0;i<Graph->Nv;i++)
	{
		if(!b[i])
		{
			return false; 
		}
	}
	return true;
}
*/

bool TopSort( LGraph Graph, Vertex TopOrder[] )
{
	int rudu[Graph->Nv];
	for(int i=0;i<Graph->Nv;i++) rudu[i]=0;
	for(int i=0;i<Graph->Nv;i++)
	{
		PtrToAdjVNode p=Graph->G[i].FirstEdge;
		while(p)
		{
			rudu[p->AdjV]+=1;
			p=p->Next;
		}
	}
	int duilie[Graph->Nv];
	for(int i=0;i<Graph->Nv;i++) duilie[i]=0;
	int first=0,rear=0;
	for(int i=0;i<Graph->Nv;i++)
	{
		if(!rudu[i]) 
		{
			duilie[rear++]=i;
			rudu[i]=-1;
		}
	}
	while(first<rear)
	{
		PtrToAdjVNode p=Graph->G[duilie[first++]].FirstEdge;
		while(p)
		{
			rudu[p->AdjV]-=1;
			p=p->Next;
		}
		for(int i =0;i<Graph->Nv;i++)
		{
			if(rudu[i]==0)
			{
				duilie[rear++]=i;
				rudu[i]=-1;
			}
		}
	}
	for(int i =0;i<Graph->Nv;i++)
	{
		if(rudu[i]>0) return false;
	}
	return true;
}



















