#include <stdio.h>
#include <stdlib.h>

int N;
int grid[1003][1003],per[1003];

int aliceCount, bobCount,used[103];
int diff, result;

int abss(int a, int b)
{
	if (a > b)
		return a - b;
	else
		b - a;
}

void print()
{

	int sum = 0;

	for (int i = 0,j=0; j < N; i++,j++)
	{
		sum = sum + grid[j][per[j]] ;
	}


	if (result > sum)
		result = sum;

}

void solve(int index)
{
	if (index == N)
	{
		print();
		return;
	}

	for (int j = 0; j < N; j++)
	{
		if (used[j] == 0)
		{
			used[j] = 1;
			per[index] = j;
			solve(index + 1);
			used[j] = 0;
		}
	}
	
 }

int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	while (T--)
	{
	

		scanf("%d", &N);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d",&grid[i][j]);
			}
		}

		for (int i = 0; i < N; i++)
			used[i] = 0;

		result = 1000000;

		solve(0);
		
		printf("%d\n", result);
	}


	//system("PAUSE");
	return 0;
}