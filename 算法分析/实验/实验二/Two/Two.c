#include<stdio.h>

#define n 10

int main()
{
	int nums[n];
	int i, j, temp;

	printf("Please input some numbers:\n");
	for(i = 0;i < n;i++)
	{
		scanf("%d", &nums[i]);
	}

	printf("Before sort:\n");
	for(i = 0;i < n;i++)
	{
		printf("%4d",nums[i]);
	}
	printf("\n");

	for(i = 0;i< n-1;i++)
	{
		for(j = 0;j < n-i-1;j++)
		{
			if(nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}

	printf("After sort:\n");
	for(i = 0;i < n;i++)
	{
		printf("%4d",nums[i]);
	}
	printf("\n");

	return 0;
}