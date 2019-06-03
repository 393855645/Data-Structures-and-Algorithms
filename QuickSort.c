#include<stdio.h>
#include<stdlib.h>


int Partition(int *array,int low,int high)
{
	int pivotkey=array[low];
	while(low<high)
	{
		while(low<high && array[high]>=pivotkey)
		{
			high--;
		}
		array[low]=array[high];
		while(low<high && array[low]<=pivotkey)
		{
			low++;
		}
		array[high]=array[low];
	}
	array[low]=pivotkey;
	return low;
}


void QuickSort(int *array,int low,int high)
{
	if(low<high)
	{
		int pivotloc=Partition(array,low,high);
		QuickSort(array,low,pivotloc-1);
		QuickSort(array,pivotloc+1,high);
	}
}


int main(void)
{
	int i,n,*array;
	printf("Please enter the array size: ");
	scanf("%d",&n);
	printf("Please enter the data: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	QuickSort(array,0,n-1);
	printf("After sort: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
