#include<stdio.h>
#include<stdlib.h>

void HeapAdjust(int *array,int s,int n)           //使堆成为最大堆，能力是先调整堆最上面的2层，然后对产生变化的子树继续调整两层，
{                                                 //没产生变化的子树没有能力调整
	int i,temp;                               //因此该方法接收仅2层的小树和前两层不符合最大堆但所有子树均符合最大堆的大树
	temp=array[s];                           
	for(i=s*2;i<=n;i*=2)                        //完全树节点*2等于该节点的左孩子节点
	{
		if(i<n && array[i]<array[i+1])      //找出左右孩子中最大的
		{
			i++;
		}
		if(temp>=array[i])                  //孩子节点中大的如果比父节点大，则赋给父节点；若父节点是大的，则不操作
		{
			break;
		}
		array[s]=array[i];                    //大的孩子节点赋给父节点
		s=i;                                  //更新父节点位置，继续调整
	}
	array[s]=temp;                               //将最初的父节点值赋给最后的节点（完成交换）

}
void HeapSort(int *array,int n)
{
	int i,temp;
	for(i=n/2;i>=1;i--)                     //i为非叶子结点的最后一位，从后向前分别调整堆
	{
		HeapAdjust(array,i,n);          //这里调整的是深度仅为2的树
	}
	for(i=n;i>1;i--)                        //此时已经完成最大堆，重复将最大的数放到最后一位，然后对前面的进行调整
	{
		temp=array[1];
		array[1]=array[i];
		array[i]=temp;
		HeapAdjust(array,1,i-1);         //这里调整的是大的树，但由于已经是最大堆，所以可以用该方法，
	}                                        //不需要担心该方法无法调整没产生变化的子树

}



int main(void)
{
	int i,n,*array;
	printf("Please enter the array size:");
	scanf("%d",&n);
	array=(int*) malloc(sizeof(int)*(n+1));      //堆排序需要算节点的位置，所以令第一位的角标为1不为0，令数组第一位为空 
	printf("Please enter the data:");
	for(i=1;i<=n;i++)                            //第一位为空
	{
		scanf("%d",&array[i]);
	}
	HeapSort(array,n);                      
	printf("After sort:");
	for(i=1;i<=n;i++)
	{
		printf("%d",array[i]);
	}
	printf("\n");

}
