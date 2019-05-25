#include<stdio.h>
#include<stdlib.h>


int BinarySearch(int *array,int key,int low,int high)
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==array[mid])
		{
			return mid;
		}
		else if(key<array[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return 0;
}


int main(void)
{
	int n,i,key,position;
	int *array;
	printf("Please enter the size of the ordered array:\n");
	scanf("%d",&n);
	array=(int*) malloc(sizeof(int)*n);
	printf("Please enter the data in ascending order:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Please enter the number you want to find:\n");
	scanf("%d",&key);
	if(position=BinarySearch(array,key,0,n-1))
	{
		printf("The position of %d is %d.\n",key,position);
	}
	else
	{
		printf("%d does not exist.\n");
	}
}
