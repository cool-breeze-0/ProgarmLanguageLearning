//express graph by adjcent matrix

#define MAX_VERTEX_NUM 100
#include<iostream>

using namespace std;

typedef enum(DG,DN,UDG,UDN) Gkind;
typedef struct cell{
	str *adj;
	bool visit;
}Vexs[MAX_VERTEX_NUM];
typedef struct{
	int adj[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum,arcnum;
	Vexs vertexs;
}Graph;

int create(Graph &G)
{
	scanf(&G.vexnum,&G.arcnum);
	for(int i=0;i<G.vexnum;i++)
	{ 
		scanf(&G.vertexs[i].adj);
		G.vertexs[i].visit=false;
	}
	
}
