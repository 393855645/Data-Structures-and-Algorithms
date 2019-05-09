#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;


typedef struct LNode             //节点数据，下一个节点地址
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;


void InitList(LinkList *L)              //二级指针，L为头指针，*L为头结点
{
	*L=(LinkList) malloc(sizeof(LNode));     //头结点（节点0），分配一个节点大小
	if(!L)
	{
		exit(OVERFLOW);
	}
	(*L)->next=NULL;
}

Status isEmpty(LinkList L)
{
	if(L->next)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}


Status InsertElem(LinkList L,int i,ElemType e)
{
	int j=0;
	LinkList s,p=L;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		return ERROR;
	}
	s=(LinkList) malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}


Status getElem(LinkList L,int i,ElemType *e)
{
	int j=1;
	LinkList p=L->next;
	while(p&&j<i)
	{
		j++;
		p=p->next;
	}
	if(!p||j>i)
	{
		return ERROR;
	}
	*e=p->data;
	return OK;
}


Status GetLength(LinkList L)
{
	int i=0;
	LinkList p=L->next;
	while(p)
	{
		i++;
		p=p->next;
	}
	return i;
}


Status compare(ElemType e1,ElemType e2)
{
	if(e1==e2)
	{
		return 0;
	}
	else if(e1<e2)
	{
		return -1;
	}
	else
		return 1;
}


Status FindElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType))
{
	int i=0;
	LinkList p=L->next;
	while(p)
	{
		i++;
		if(!compare(p->data,e))
		{
			return i;
		}
		p=p->next;
	}
	return 0;	
}


Status PreElem(LinkList L,ElemType e,ElemType *pre_e)
{
	LinkList p=L->next,q;
	while(p->next)
	{
		q=p->next;
		if(q->data==e)
		{
			*pre_e=p->data;
			return OK;
		}
		p=q;
	}
	return ERROR;
}


Status NextElem(LinkList L,ElemType e,ElemType *next_e)
{
	LinkList p=L->next,q;
	while(p->next)
	{
		q=p->next;
		if(p->data==e)
		{
			*next_e=q->data;
			return OK;
		}
		p=q;
	}
	return ERROR;
}


Status DeleElem(LinkList L,int i,ElemType *e)
{
	int j=0;
	LinkList p=L,q;
	while(p->next&&j<i-1)
	{
		j++;
		p=p->next;
	}
	q=p->next;
	p->next=q->next;
	*e=q->data;
	free(q);
	return OK;
}


void visit(ElemType e)
{
	printf("%d ",e);
}


void TraverseList(LinkList L,void (*visit)(ElemType))
{
	LinkList p=L->next;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}
}


void DestroyList(LinkList *L)
{
	LinkList temp;
	while(*L)
	{
		temp=(*L)->next;
		free(*L);
		*L=temp;
	}
}


int main(void)
{
	LinkList L;
	InitList(&L);
	ElemType e;
	int i;
	if(L)
	{
		printf("Init success!\n");
	}
	if(isEmpty(L))
	{
		printf("List is empty.\n");
	}
	for(i=0;i<10;i++)
	{
		InsertElem(L,i+1,i);
	}
	if(getElem(L,1,&e))
	{
		printf("The first element is %d.\n",e);
	}
	printf("Length is %d.\n",GetLength(L));
	printf("The 5 is at %d.\n",FindElem(L,5,*compare));
	PreElem(L,6,&e);
	printf("The 6`s previous element is %d.\n",e);
	NextElem(L,6,&e);
	printf("The 6`s next element is %d.\n",e);
	DeleElem(L,1,&e);
	printf("Deleted first element is %d.\n",e);
	printf("List:");
	TraverseList(L,visit);
	DestroyList(&L);
	if(!L)
	{
		printf("\nDestroy success.\n");
	}
}
