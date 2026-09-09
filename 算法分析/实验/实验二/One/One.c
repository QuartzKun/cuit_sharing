#include<stdio.h>

#define n 10

int main()
{
	int nums[n];
	int i, j, min, temp;

	printf("Please input some numbers:\n");
	for(i = 0;i < n;i++)
	{
		scanf("%d",&nums[i]);
	}

	printf("Before swap:\n");
	for(i = 0;i < n;i++)
	{
		printf("%2d", nums[i]);
	}
	printf("\n");

	for(i = 0;i < n-1;i++)
	{
		min = i;
		for(j = i+1;j < n;j++)
		{
			if(nums[j] < nums[min])
			{
				temp = nums[min];
				nums[min] = nums[j];
				nums[j] = temp;
			}
		}
	}

	printf("After swap:\n");
	for(i = 0;i < n;i++)
	{
		printf("%2d", nums[i]);
	}
	printf("\n");

	return 0;
}