#include<stdio.h>

const int n = 5;
static int arc[100][100];
static color[100];

void ColorGraph();
int Ok(int i);

int main()
{
	int m;
	int i, j;

	printf("请输入颜色的个数：");
	scanf("%d",&m);

	printf("请输入无向图点和边的关系：\n");
	for(i = 0;i < n;i ++)
	{
		for(j = 0;j < n;j++)
		{
			scanf("%d",&arc[i][j]);
		}
	}

	ColorGraph();
	printf("out color is\n");
	for(i = 0;i < n;i++)
	{
		printf("%d ",color[i]);
	}
	printf("\n");

	return 0;
}

void ColorGraph()
{
	int k = 0;
	int i;
	int flag = 1;
	while(flag == 1)
	{
		k ++;
		flag = 0;
		for(i = 0;i < n;i++)
		{
			if(color[i] == 0)
			{
				color[i] = k;
				if(!Ok(i))
				{
					color[i] = 0;
					flag = 1;
				}
			}
		}
	}
}
int Ok(int i)
{
	int j;
	for(j = 0;j < n;j++)
	{
		if(arc[i][j] == 1 && color[i] == color[j])
		{
			return 0;
		}
	}
	return 1;
}