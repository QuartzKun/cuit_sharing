#include<stdio.h>

#define N 10

int Input(int nums[]);
void OutputO(int nums[]);
void OutputT(int num, int count);
int Sort(int nums[]);
int Search_Bin(int nums[]);

int main()
{
	int num;
	int nums[N];

	num = Search_Bin(nums);
	if (num != -1)
	{
		printf("\n");
		printf("查找成功！\n");
		printf("成功查找到的位置下标为：%d\n", num);
	}
	else
	{
		printf("查找失败！\n");
	}
	printf("\n");

	return 0;
}

int Input(int nums[])
{
	int i;

	printf("请输入一些数字：\n");
	for (i = 0;i < N;i++)
	{
		scanf("%d", &nums[i]);
	}
	printf("\n");

	return 1;
}

void OutputO(int nums[])
{
	int i;

	for (i = 0;i < N;i++)
	{
		printf("%d	", nums[i]);
	}
	printf("\n");
}

void OutputT(int num, int count)
{
	printf("查找的次数是：%d； 查找到的数值为：%d\n", count, num);
}

int Sort(int nums[])
{
	int i, j;
	int temp;

	for (i = 0;i < N;i++)
	{
		for (j = 0;j < N - i - 1;j++)
		{
			if (nums[j] > nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}

	return 1;
}

int Search_Bin(int nums[])
{
	int b1 = -1, b2 = -1;
	int key;
	int low = 0, high = N;
	int mid, count = 0;

	b1 = Input(nums);
	if (b1)
	{
		printf("数值输入成功！\n");
		printf("Before sort:\n");
		OutputO(nums);
	}
	printf("\n");

	b2 = Sort(nums);
	if (b2)
	{
		printf("数排序成功！\n");
		printf("After sort:\n");
		OutputO(nums);
	}
	printf("\n");

	printf("请输入你需要查找的数字：");
	scanf("%d", &key);

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == nums[mid])
			return mid;
		else if (key < nums[mid])
			high = mid - 1;
		else
			low = mid + 1;
		count++;
		OutputT(nums[mid],count);
	}

	return -1;
}