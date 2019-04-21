#include<stdio.h>
int MaxSubsequenceSum(int *a,int n);
int main(void)
{
	int ans=0;
	int a[13]={0,-3,6,8,-20,21,8,-9,10,-1,3,6,5};
	ans=MaxSubsequenceSum(a,13);
	printf("%d\n",ans);
}

int MaxSubsequenceSum(int *a,int n)
{
	int ThisSum=0,MaxSum=0;
	int i;
	for(i=0;i<n;i++)
	{
		ThisSum+=a[i];
		if(ThisSum>MaxSum)
			MaxSum=ThisSum;
		else if(ThisSum<0)
			ThisSum=0;
	}	
	return MaxSum;
}
