#include<stdio.h>
#include<stdlib.h>


void ShellSort(int *array,int n)
{
	int k;
	k=n/2;
	while(k>0)
	{
		int i,j,temp;
		for(i=k;i<n;i++)
		{
			if(array[i]<array[i-k])
			{
				temp=array[i];
				for(j=i-k;j>=0&&temp<array[j];j-=k)
				{
					array[j+k]=array[j];
				}
				array[j+k]=temp;
			}
		}
		k=k/2;
	}
	
}


int main(void)
{
	int i,n;
	int *array;
	printf("Please enter the size of the array: ");
	scanf("%d",&n);
	array=(int*) malloc(sizeof(int)*n);
	printf("Please enter the data(separate with spacese): ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	ShellSort(array,n);
	printf("Data after sort: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
