#include<stdio.h>

#define max 5
#define num 9

int Max(int n, int m);

int main()
{
	int v[max], w[max];
	int bag;
	int dp[max][num] = {{0}};
	int i, j;

	printf("Please input the weight of bag:");
	scanf("%d",&bag);

	printf("\nPlease input some weight of things:\n");
	for(i = 0;i < max;i++)
	{
		scanf("%d",&v[i]);
	}
	printf("\nPlease input some value of things:\n");
	for(i = 0;i < max;i++)
	{
		scanf("%d",&w[i]);
	}

	for(i = 1;i < max;i++)
	{
		for(j = 1;j <= bag;j++)
		{
			if(j < v[i])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = Max(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
		}
	}

	printf("\nFinally:\n");
	for(i = 0;i < max;i++)
	{
		for(j = 0;j < num;j++)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}

	printf("\nThe best: dp[%d][%d] = %d\n",i-1, j-1, dp[i-1][j-1]);

	return 0;
}

int Max(int n, int m)
{
	if(n > m)
		return n;
	else
		return m;
}
