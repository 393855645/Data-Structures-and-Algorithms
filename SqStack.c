#include<stdio.h>
#include<stdlib.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 20
#define INCREMENT_SIZE 5


typedef int SElemType;
typedef int Status;


typedef struct
{
	SElemType *base;
	SElemType *top;
	int size;
}SqStack;

Status InitStack(SqStack *S)
{
	S->base=(SElemType*) malloc(INIT_SIZE * sizeof(SElemType));
	if(!S->base)
	{
		exit(OVERFLOW);
	}
	S->top=S->base;
	S->size=INIT_SIZE;
	return OK;
}

Status IsEmpty(SqStack S)
{
	if(S.top==S.base)
		return TRUE;
	else 
		return FALSE;
}


Status Push(SqStack *S,SElemType e)
{
	if((S->top-S->base)/sizeof(SElemType)>=S->size)
	{	S->base=(SElemType*) realloc(S->base,(S->size+INCREMENT_SIZE)*sizeof(SElemType));
		if(!S->base)
		{
			exit(OVERFLOW);
		}
		S->top=S->base+S->size;
		S->size+=INCREMENT_SIZE;
	}
	*(S->top)=e;
	S->top+=sizeof(SElemType);
	return OK;
}

Status GetTop(SqStack S,SElemType *e)
{
	if(S.top>S.base)
	{
		*e=*(S.top-sizeof(SElemType));
		return OK;
	}
	else
	{
		return ERROR;
	}
}


Status GetLength(SqStack S)
{
	return (S.top-S.base)/sizeof(SElemType);
}


Status Pop(SqStack *S,SElemType *e)
{
	if(S->top==S->base)
	{
		return ERROR;
	}
	S->top-=sizeof(SElemType);
	*e=*(S->top);
	return OK;
}

void visit(SElemType e)
{
	printf("%d ",e);
}

Status TraverseStack(SqStack S,void (*visit)(SElemType))
{	
	SElemType *p;
	p=S.base;
	while(p<S.top)
	{
		visit(*p);
		p+=sizeof(SElemType);
	}
	return OK;
	
}


Status DestroyStack(SqStack *S)
{
	free(S->base);
	S->base=NULL;
	S->top=NULL;
	S->size=0;
	return OK;
}
int main(void)
{
	SqStack S;
	if(InitStack(&S))
	{
		SElemType e;
		int i;
		printf("Init_succes\n");
		if(IsEmpty(S))
		{
			printf("Stack is empty.\n");
		}
		for(i=0;i<10;i++)
		{
			Push(&S,i);
		}
		GetTop(S,&e);
		printf("The first element is %d.\n",e);
		printf("Length is %d.\n",GetLength(S));		
		Pop(&S,&e);	
		printf("Poped element is %d.\n",e);		
		TraverseStack(S,*visit);
		printf("\nLength is %d.\n",GetLength(S));
		if(DestroyStack(&S))
		{
			printf("Destroy_success.\n");
		}
	}
}
