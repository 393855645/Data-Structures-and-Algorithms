#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_NUM 20
typedef int Status;
typedef int QElemType;
typedef char VexType;               //vertex


typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode,*EdgeLink;


typedef struct VexNode
{
	VexType data;
	EdgeNode *firstEdge;
}VexNode,AdjList[MAX_NUM];

typedef struct
{
	AdjList adjList;
	int vexNum,edgeNum;          
}ALGraph;                          //Adjacency List Graph


Status CreatGraph(ALGraph *G)
{
	int i,j,k;
	EdgeLink e;
	printf("Please enter the vexnum and the edgenum:\n");
	scanf("%d",&G->vexNum);
	scanf("%d",&G->edgeNum);
	//getchar();
	printf("Please enter the data of each vex:\n");
	for(i=0;i<G->vexNum;i++)
	{
		scanf("%c",&G->adjList[i].data);
		if(G->adjList[i].data=='\n')
		{
			i--;
			continue;
		}
		G->adjList[i].firstEdge=NULL;
	}
	printf("Please enter the vex number of edges (vi,vj):\n");
	for(k=0;k<G->edgeNum;k++)
	{
		scanf("%d",&i);
		scanf("%d",&j);
		
		e=(EdgeLink) malloc(sizeof(EdgeNode));
		e->adjvex=j;
		e->next=G->adjList[i].firstEdge;
		G->adjList[i].firstEdge=e;

		e=(EdgeLink) malloc(sizeof(EdgeNode));
		e->adjvex=i;
		e->next=G->adjList[j].firstEdge;
		G->adjList[j].firstEdge=e;
	}
	return OK;
}


int visited[MAX_NUM];


void DFS(ALGraph G,int i)
{
	EdgeLink p;
	visited[i]=TRUE;
	printf("%c ",G.adjList[i].data);
	p=G.adjList[i].firstEdge;
	while(p)
	{
		if(!visited[p->adjvex])
		{
			DFS(G,p->adjvex);
		}
		p=p->next;
	}
}
Status DFSTraverse(ALGraph G)
{
	int i;
	for(i=0;i<MAX_NUM;i++)
	{
		visited[i]=FALSE;
	}
	for(i=0;i<G.vexNum;i++)
	{
		if(!visited[i])
		{
			DFS(G,i);
		}
	}
	return OK;
}



typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;


typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


Status InitQueue(LinkQueue *Q)
{
	Q->front=Q->rear=(QueuePtr) malloc(sizeof(QNode));
	if(!Q->front)
	{
		exit(OVERFLOW);
	}
	Q->front->next=NULL;
	return OK;
}


Status IsEmpty(LinkQueue Q)
{
	if(Q.front->next==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


Status EnQueue(LinkQueue *Q,QElemType e)
{
	QueuePtr p=(QueuePtr) malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;
}


Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(Q->rear=p)
	{
		Q->rear=Q->front;
	}
	free(p);
	return OK;
}


Status BFSTraverse(ALGraph G)
{
	int i;
	EdgeLink p;
	LinkQueue Q;
	InitQueue(&Q);
	for(i=0;i<MAX_NUM;i++)
	{
		visited[i]=FALSE;
	}
	for(i=0;i<G.vexNum;i++)
	{
		if(!visited[i])
		{
			visited[i]=TRUE;
			printf("%c ",G.adjList[i].data);
			EnQueue(&Q,i);
			while(!IsEmpty(Q))
			{
				DeQueue(&Q,&i);
				p=G.adjList[i].firstEdge;
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex]=TRUE;
						printf("%c ",G.adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);
					}
					p=p->next;
				}
				
			}
		
		}
	}
	return OK;
}

int main(void)
{
	ALGraph G;
	CreatGraph(&G);
	printf("Depth first seach traverse:");
	DFSTraverse(G);
	printf("\nBreadth first search traverse:");
	BFSTraverse(G);
	printf("\n");

}
