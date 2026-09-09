#include<stdio.h>

#define n 10
void sort(int nums[]);

int main()
{
	int nums[n];
	int i = 0;

	printf("Please input some numbers:\n");
	for(i;i < n;i++)
	{
		scanf("%d",&nums[i]);
	}

	printf("Before sort:\n");
	for(i = 0;i < n;i++)
	{
		printf(" %d ",nums[i]);
	}
	printf("\n");

	sort(nums);

	printf("After sort:\n");
	for(i = 0;i < n;i++)
	{
		printf(" %d ",nums[i]);
	}
	printf("\n");

	return 0;
}

void sort(int nums[])
{
	int temp;
	int i, j = 0, k = n-1;

	while(j < k)
	{
		for(i = j;i < k;i++)
		{
			if(nums[i] > nums[i+1])
			{
				temp = nums[i];
				nums[i] = nums[i+1];
				nums[i+1] = temp;
			}
		}
		k--;
		for(i = k;i > j;i--)
		{
			if(nums[i] < nums[i-1])
			{
				temp = nums[i];
				nums[i] = nums[i-1];
				nums[i-1] = temp;
			}
		}
		j++;
	}
}