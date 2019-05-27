#include<stdio.h>
#include<stdlib.h>


void InsertSort(int *array,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		if(array[i]<array[i-1])
		{
			temp=array[i];
			for(j=i-1;j>=0&&temp<array[j];j--)
			{
				array[j+1]=array[j];
			}
			array[j+1]=temp;
		}
	}

}

int main(void)
{
	int *array;
	int n,i;
	printf("Please enter the size of the array:");
	scanf("%d",&n);
	array=(int*) malloc(sizeof(int)*n);
	printf("Please enter the data(separate by spacese):");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	InsertSort(array,n);
	printf("The array`s data in order are:");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
