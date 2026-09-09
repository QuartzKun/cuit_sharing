#include<stdio.h>
#include <stdlib.h>

#define Max 20

int Coins[Max];//各个硬币的值    下标0不用
int F[Max];//存放每次最大币值

int CoinMax(int n);
int MAX(int x, int y);

int main()
{
	int i;
	int n, num = 0;
	int SeleCoin[Max];

	printf("请输入有多少个硬币：");
	scanf("%d",&n);

	printf("请分别输入硬币的值：\n");
	for(i = 1;i <= n;i++)
	{
		scanf("%d",&Coins[i]);
	}

	printf("最大币值为：%d\n",CoinMax(n));

//找到取得最大币值的各个币值(回溯)
	for(i = n;i >= 1;i--)
	{
		if(F[i] == F[i-1])
		{
			SeleCoin[num++] = Coins[--i];
		}
		else
		{
			SeleCoin[num++] = Coins[i--];
		}
		i--;//使其一次性-2
	}

	printf("各个币值为：");
	for(i = 0;i < num;i++)
	{
		printf("%4d",SeleCoin[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}

//找最大币值
int CoinMax(int n)
{
	int i;

	Coins[0] = 0;
	F[0] = 0;
	F[1] = Coins[1];

	for(i = 2;i <= n;i++)
	{
		F[i] = MAX(Coins[i] + F[i - 2], F[i - 1]);
	}

	return F[n];
}
//选择较大的币值
int MAX(int x, int y)
{
	return (x > y) ? x : y;
}