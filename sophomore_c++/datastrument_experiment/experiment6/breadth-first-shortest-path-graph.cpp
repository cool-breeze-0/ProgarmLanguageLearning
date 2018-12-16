//广度优先遍历求最短路径 
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

void ShortestDist( LGraph Graph, int dist[], Vertex S );

int main()
{
    int dist[MaxVertexNum];
    Vertex S, V;
    LGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist( G, dist, S );

    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);

    return 0;
}

void ShortestDist( LGraph Graph, int dist[], Vertex S )
{
	int duilie[100];
	for(int i=0;i<MaxVertexNum;i++) dist[i]=-1;
	int first=0,rear=0;
	int llong=1;
	dist[S]=0;
	duilie[first]=S;
	rear+=1;
	int a=1;
	while(first<rear)
	{
		PtrToAdjVNode p=Graph->G[duilie[first]].FirstEdge;
		while(p)
		{
			if(dist[p->AdjV]==-1) 
			{
				dist[p->AdjV]=llong;
				duilie[rear++]=p->AdjV;
			}
			p=p->Next;
		}
		if(first+1==a) 
		{
			llong++;
			a=rear;
		}
		first++;
	}
}
