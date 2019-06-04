#include<stdio.h>
#include<stdlib.h>

void HeapAdjust(int *array,int s,int n)
{
	int i,temp;
	temp=array[s];
	for(i=s*2;i<=n;i*=2)
	{
		if(i<n && array[i]<array[i+1])
		{
			i++;
		}
		if(temp>=array[i])
		{
			break;
		}
		array[s]=array[i];
		s=i;
	}
	array[s]=temp;

}
void HeapSort(int *array,int n)
{
	int i,temp;
	for(i=n/2;i>=1;i--)
	{
		HeapAdjust(array,i,n);
	}
	for(i=n;i>1;i--)
	{
		temp=array[1];
		array[1]=array[i];
		array[i]=temp;
		HeapAdjust(array,1,i-1);
	}

}



int main(void)
{
	int i,n,*array;
	printf("Please enter the array size:");
	scanf("%d",&n);
	array=(int*) malloc(sizeof(int)*(n+1));
	printf("Please enter the data:");
	for(i=1;i<=n;i++)
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
