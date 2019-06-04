#include<stdio.h>
#include<stdlib.h>


void SelectSort(int *array,int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(array[k]>array[j])
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=array[i];
			array[i]=array[k];
			array[k]=temp;
		}
	}
}


int main(void)
{
	int i,n,*array;
	printf("Please enter the array size:");
	scanf("%d",&n);
	printf("Please enter the data:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	SelectSort(array,n);
	printf("After sort: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
