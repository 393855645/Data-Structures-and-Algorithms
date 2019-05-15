#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


Status CreatBiTree(BiTree *T)
{
	TElemType e;
	scanf("%d",&e);
	if(e==0)
	{
		*T=NULL;
	}
	else
	{
		*T=(BiTree) malloc(sizeof(BiTNode));
		if(!T)
		{
			exit(OVERFLOW);
		}
		(*T)->data=e;
		CreatBiTree(&(*T)->lchild);
		CreatBiTree(&(*T)->rchild);
	}
	return OK;
}
void visit(TElemType e)
{
	printf("%d ",e);
}

Status PreOrderTraverse(BiTree T,void(*visit)(TElemType))
{
	if(T)
	{
		visit(T->data);
		PreOrderTraverse(T->lchild,*visit);
		PreOrderTraverse(T->rchild,*visit);
	}
}


Status InOrderTraverse(BiTree T,void (*visit)(TElemType))
{
	if(T)
	{
		InOrderTraverse(T->lchild,*visit);
		visit(T->data);
		InOrderTraverse(T->rchild,*visit);
	}
}


Status PostOrderTraverse(BiTree T, void(*visit)(TElemType))
{
	if(T)
	{
		PostOrderTraverse(T->lchild,*visit);
		PostOrderTraverse(T->rchild,*visit);
		visit(T->data);
	}
}
int main(void)
{
	BiTree T;
	printf("Creat BiTree,enter \"0\"will creat empty tree.");
	CreatBiTree(&T);
	printf("Preorder traversal:");
	PreOrderTraverse(T,*visit);
	printf("\nInorderTraverse:");
	InOrderTraverse(T,*visit);
	printf("\nPostOrderTraverse:");
	PostOrderTraverse(T,*visit);
	printf("\n");

	return 0;


}
