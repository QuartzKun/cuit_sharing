#include<stdio.h>

#define N 10

void Sort(int nums[]);
void StructFun(int nums[]);
void Dsort(int nums[], int index, int n);

int main()
{
	int i;
	int nums[N];
	printf("Please input %d numbers:\n",N);
	for(i = 0;i < N;i++)
	{
		scanf("%d", &nums[i]);
	}

	printf("Before sort:\n");
	for(i = 0;i < N;i++)
	{
		printf("%d  ",nums[i]);
	}
	printf("\n");

	Sort(nums);
	printf("After sort:\n");
	for(i = 0;i < N;i++)
	{
		printf("%d  ",nums[i]);
	}
	printf("\n");	

	return 0;
}

void Sort(int nums[])
{
	int i;
	int temp;

	StructFun(nums);

	for(i = N;i > 0;i--)
	{
		temp = nums[0];
		nums[0] = nums[i-1];
		nums[i-1] = temp;

		Dsort(nums, 0, i-1);
	}
}

void StructFun(int nums[])
{
	int i, Findex, Nindex;
	int temp;

	for(i = 0;i < N;i++)
	{
		Nindex = i;
		Findex = ( i - 1 ) / 2;

		while(nums[Nindex] > nums[Findex])
		{
			temp = nums[Nindex];
			nums[Nindex] = nums[Findex];
			nums[Findex] = temp;

			Nindex = Findex;
			Findex = ( Nindex - 1 ) / 2;
		}
		
	}
}

void Dsort(int nums[], int index, int n)
{
	int Max, Lindex, Rindex;
	int temp;

	Lindex = 2 * index + 1;
	Rindex = 2 * index + 2;

	while(Lindex < n)
	{
		if(nums[Lindex] < nums[Rindex] && Rindex < n)
		{
			Max = Rindex;
		}
		else
		{
			Max = Lindex;
		}

		if(nums[index] > nums[Max])
		{
			Max = index;
		}

		if(index == Max)
		{
			break;
		}

		temp = nums[Max];
		nums[Max] = nums[index];
		nums[index]= temp;

		index = Max;
		Lindex = 2 * index + 1;
		Rindex = 2 * index + 2;
	}
}
