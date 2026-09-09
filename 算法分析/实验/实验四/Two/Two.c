/*
	时间复杂度：O(nlgn)
	空间复杂度：O(n)
	稳定
*/

#include<stdio.h> 

#define N 10

void Mer_Sort(int nums[]);
void Sort(int nums[],int TmpA[],int L,int R);
void Merge(int nums[],int Rnums[],int L,int R,int Rend);

int main()
{
	int nums[N];
	int i;

	printf("Please input %d numbers:\n", N);
	for (i = 0;i < N;i++)
	{
		scanf("%d", &nums[i]);
	}

	printf("Before sort:\n");
	for (i = 0;i < N;i++)
	{
		printf("%d	", nums[i]);
	}
	printf("\n");

	Mer_Sort(nums);
	printf("After sort:\n");
	for (i = 0;i < N;i++)
	{
		printf("%d	", nums[i]);
	}
	printf("\n");

	return 0;
}

void Mer_Sort(int nums[])
{
	int tmp[N];
	if(tmp)
	{
		Sort(nums,tmp,0,N-1);
	}
}
void Sort(int nums[],int TmpA[],int L,int R)
{
	int mid;

	if(L < R)
	{
		mid = (L + R) / 2;
		Sort(nums, TmpA, L, mid);
		Sort(nums, TmpA, mid+1, R);

		Merge(nums,TmpA, L, mid+1, R);
	}
}
void Merge(int nums[],int Rnums[],int L,int R,int Rend)
{
	int i;
	int Lend,k,n;
	Lend = R-1;
	k = L;
	n = Rend - L + 1;

	while(L <= Lend && R <= Rend)
	{
		if(nums[L] <= nums[R])
			Rnums[k++] = nums[L++];
		else
			Rnums[k++] = nums[R++];
	}

	while(L <= Lend)
			Rnums[k++] = nums[L++];
	while(R <= Rend)
			Rnums[k++] = nums[R++];

	for(i = 0;i < n;i++,Rend--)
	{
		nums[Rend] = Rnums[Rend];
	}
}
