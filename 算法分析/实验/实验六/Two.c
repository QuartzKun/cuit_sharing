#include<stdio.h>
 
#define num 9
#define Infinity 65535

void MinSpanTree_Prime(int graphic[num][num])
{
	int lowcost[num];
	int adjvex[num];
	int sum = 0;
	int index, min;
	int i, j;

	memset(adjvex, 0, sizeof(adjvex));

	for (i = 0; i < num; i++)
		lowcost[i] = graphic[0][i];
 
	for (i = 1; i < num; i++)
	{
		min = Infinity;
		
		for (j = 1; j < num; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				index = j;
				min = lowcost[j];
			}
		}
		sum += min;
		lowcost[index] = 0;
		printf("%d -> %d\n", adjvex[index], index);

		for (j = 1; j < num; j++)
		{
			if (lowcost[j] != 0 && graphic[index][j] < lowcost[j])
			{
				lowcost[j] = graphic[index][j];
				adjvex[j] = index;
			}
		}
	}
	printf("sum = %d\n", sum);
}
 
int main()
{
	int i, j;
	int graphic[num][num];

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (i == j)
				graphic[i][j] = 0;
			else
				graphic[i][j] = Infinity;
		}
	}
	graphic[0][1] = 1;
	graphic[0][2] = 5;
	graphic[1][0] = 1;
	graphic[1][2] = 3;
	graphic[1][3] = 7;
	graphic[1][4] = 5;
	graphic[2][0] = 5;
	graphic[2][1] = 3;
	graphic[2][4] = 1;
	graphic[2][5] = 7;
	graphic[3][1] = 7;
	graphic[3][4] = 2;
	graphic[3][6] = 3;
	graphic[4][1] = 5;
	graphic[4][2] = 1;
	graphic[4][3] = 2;
	graphic[4][5] = 3;
	graphic[4][6] = 6;
	graphic[4][7] = 9;
	graphic[5][2] = 7;
	graphic[5][4] = 3;
	graphic[5][7] = 5;
	graphic[6][3] = 3;
	graphic[6][4] = 6;
	graphic[6][7] = 2;
	graphic[6][8] = 7;
	graphic[7][4] = 9;
	graphic[7][5] = 5;
	graphic[7][6] = 2;
	graphic[7][8] = 4;
	graphic[8][6] = 7;
	graphic[8][7] = 4;
 
	MinSpanTree_Prime(graphic);
 
	return 0;
}