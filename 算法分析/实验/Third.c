#include<stdio.h>
#include <stdlib.h>

#define MAX 10

int m,n;
int arr[MAX][MAX]; //储存原始方格元素
int F[MAX][MAX]; //保存收集到的最大硬币数
int H[MAX][MAX];//进行回溯操作时，保存路线坐标

void HuiSu();
void FindMax();
int Max(int a,int b);

int main()
{
	int i, j;

	printf("请输入方格的行数和列数：\n");
	scanf("%d %d", &m, &n);

	for(i = 1;i <= m;i++)
	{
		printf("请输入第 %d 行的 %d 个数：(只能出现0或1)\n",i,n);
		for(j = 1;j <= n;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	FindMax();
	printf("收集的路线为：\n");
	HuiSu();

	system("pause");
	return 0;
}
//寻找最多收集硬币数
void FindMax()
{
	int i, j;

	for(i = 1;i <= m;i++)
	{
		for(j = 1;j <= n;j++)
		{
			F[i][j] = Max(F[i-1][j], F[i][j-1]) + arr[i][j];
		}
	}
	printf("\n最多搜集 %d 个硬币。\n",F[m][n]);
}
int Max(int a,int b)
{
	return (a >= b) ? a : b;
}
//收集最多硬币的路径
void HuiSu()
{
	int i, j;
	int a = m;
	int b = n;
	H[1][1] = 1;
	H[m][n] = 1;

	while(a >= 1 && b >= 1)
	{
		if(F[a-1][b] >= F[a][b-1])
		{
			H[a-1][b] = 1;
			a--;
		}
		else
		{
			H[a][b-1] = 1;
			b--;
		}
	}
	for(i = 1;i <= m;i++)
	{
		for(j = 1;j <= n;j++)
		{
			if(H[i][j] == 1)
			{
				if(i == m && j == n)
					printf("（%d，%d）\n",m,n);
				else
					printf("（%d，%d）-->",i,j);
			}
		}
	}
}