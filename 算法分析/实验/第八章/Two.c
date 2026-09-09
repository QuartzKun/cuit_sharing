#include<stdio.h>
#include <stdlib.h>

#define Max 10

int MIN(int x, int y);

int main()
{
	int Coins[3] = {1, 3, 4};
	int F[Max];
	int n;
	int i, j;

	printf("请输入需要找零的值：");
	scanf("%d",&n);

	for(i = 0;i <= n;i++)
	{
		F[i] = i;//初始化为i,任意金额都可以由一元组成
	}
	for(i = 0;i < 3;i++)
	{
		F[Coins[i]] = 1;//如果当前金额为现有货币币种，那一张就够
	}
	for(i = 1;i <= n;i++)
	{
		for(j = 0;j < 3;j++)
		{
			if(Coins[j] > i)
				continue;
			F[i] = MIN(F[i], F[i - Coins[j]] + 1);//当前金额i是否可以通过一张面额为Coin[j]的币种和金额为i-Coin[j]的数量组成更小的张数。
		}
	}
	printf("需要的硬币数为：%d\n",F[n]);

	system("pause");
	return 0;
}
int MIN(int x, int y)
{
	return (x < y) ? x : y;
}