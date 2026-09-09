#include<stdio.h>

int main()
{
	int num[255][255];
	int n;
	int i, j;
	printf("Please input one number:");
	scanf("%d",&n);
	printf("Please input some numbers:\n");
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= i;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}

	for(i = n-1;i >= 1;i--)
	{
		for(j = 1;j <= i;j++)
		{
			if(num[i+1][j] >= num[i+1][j+1])
				num[i][j] += num[i+1][j];
			else
				num[i][j] = num[i+1][j+1];
		}
	}

	printf("%d\n",num[1][1]);

	return 0;
}