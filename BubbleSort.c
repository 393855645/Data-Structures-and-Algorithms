#include<stdio.h>
#include<stdlib.h>


void BubbleSort(int *array,int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
	}
}



int main(void)
{
	int i,n;
	int *array;
	printf("Please enter the array size: ");
	scanf("%d",&n);
	array=(int*) malloc(sizeof(int)*n);
	printf("Please enter the data(separate with spaces): ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	BubbleSort(array,n);
	printf("After sort: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
