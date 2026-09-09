#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 10

void Produce(int coins[]);
int Scoins(int coins[],int F,int T);
int ChechCoins(int coins[],int F,int T);

int main()
{
	int coins[N];
	int i,QuaOne,QuaTwo;
	int F_coin;

	Produce(coins);

	for(i = 0;i < N;i++)
		printf("%d\t",i);
	printf("\n");

	for(i = 0;i < N;i++)
		printf("%d\t",coins[i]);
	printf("\n");

	F_coin = ChechCoins(coins,0,N-1);
	printf("F_coin = %d\n",F_coin);

	QuaOne = coins[F_coin] > coins[F_coin + 1];
	QuaTwo = coins[F_coin] > coins[F_coin - 1];
	if(QuaOne || QuaTwo)
		printf("第%d枚是假币，假币较重。\n",F_coin + 1);
	else
		printf("第%d枚是假币，假币较轻。\n",F_coin + 1);

	return 0;
}

void Produce(int coins[])
{
	int i,QuaOne,QuaTwo;
	int Size;

	srand((unsigned int)time(NULL));

	QuaOne = rand() % 10 + 1;
	for(i = 0;i < N;i++)
		coins[i] = QuaOne;
	
	do
	{
		QuaTwo = rand() % 20 +1;
	}while(QuaTwo == QuaOne);

	Size = rand() % N;
	coins[Size] = QuaTwo;
}

int Scoins(int coins[],int F,int T)
{
	int i;
	int sum = 0;

	for(i = F;i <= T;i++)
		sum += coins[i];

	return sum;
}

int ChechCoins(int coins[],int F,int T)
{
	int n = T - F + 1;
	int QuaOne,QuaTwo;
	int size = 0,sizeO,sizeT,sizeTh;

	if(n == 1)
	{
		QuaOne = coins[F] == coins[F + 2];
		QuaTwo = coins[F] == coins[F - 2];
		if(QuaOne || QuaTwo)
			size = 0;
		else
			size = F;
	}
	else
	{
		if(n % 2 == 0)
		{
			QuaOne = Scoins(coins,F,F + n/2 - 1);
			QuaTwo = Scoins(coins,T - n/2 + 1,T);
			if(QuaOne == QuaTwo)
				size = 0;
			else
			{
				sizeO = ChechCoins(coins,F,F + n/2 - 1);
				if(sizeO == 0)
				{
					sizeT = ChechCoins(coins,F + n/2 - 1,T);
					if(sizeT != 0)
						size = sizeT;
					else
						size = 0;
				}
				else
					size = sizeO;
			}
		}
		else
		{
			sizeTh = ChechCoins(coins,F + 1,T);
			if(sizeTh == 0)
			{
				if(coins[F] != coins[F+1])
					size = F;
			}
			else
				size = sizeTh;
		}
	}

	return size;
}
