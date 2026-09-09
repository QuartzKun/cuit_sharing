/*
	时间复杂度：O(n log2 n)
	空间复杂度：O(n log2 n)
	不稳定
*/

#include<stdio.h>

#define N 10

void Sort(int nums[],int left,int right);

int main()
{
	int nums[N];
	int i;

	printf("Please input %d numbers:\n",N);
	for(i = 0;i < N;i++)
	{
		scanf("%d",&nums[i]);
	}

	printf("Before sort:\n");
	for(i = 0;i < N;i++)
	{
		printf("%d	",nums[i]);
	}
	printf("\n");

	Sort(nums,0,N);
	printf("After sort:\n");
	for(i = 0;i < N;i++)
	{
		printf("%d	",nums[i]);
	}
	printf("\n");

	return 0;
}

void Sort(int nums[],int left,int right)
{
	int i;
	int low,high,k;
	int temp;

	if(left >= right)
		return;

	k = nums[left];
	low = left;
	high = right;

	while(low < high)
	{
		while(nums[high] >= k && low < high)
			high--;
		while(nums[low] <= k && low < high)
			low++;
		if(low < high)
		{
			temp = nums[low];
			nums[low] = nums[high];
			nums[high] = temp;
		}
	}

	nums[left] = nums[low];
	nums[low] = k;

	printf("k = %d    low = %d    high = %d\n",k,low,high);
	for(i = 0;i < N;i++)
		printf("%d	",nums[i]);
	printf("\n");

	Sort(nums,left,low-1);
	Sort(nums,low+1,right);
}