#include <stdio.h>
#include <stdlib.h>

int N, M,cnt,p;
char input[102][102],res[102];

void dfs1(int i, int j)
{
	if (i < 0 || i == N || j < 0 || j == M || input[i][j] != 'X')
	{
		return;
	}
	
	input[i][j] = '*';

	dfs1(i - 1, j);
	dfs1(i, j - 1);
	dfs1(i + 1, j);
	dfs1(i, j + 1);

}

void dfs(int x, int y)
{
	if (x < 0 || x == N || y < 0 || y == M || input[x][y] == '.')
	{
		return;
	}

	if (input[x][y] == 'X')
	{
		dfs1(x, y);
		cnt++;
	}

	input[x][y] = '.';

	dfs(x-1, y);
	dfs(x, y - 1);
	dfs(x + 1, y);
	dfs(x, y + 1);

}

void sort_arr()
{
	int swap;

	for (int i = 0; i < p-1; i++)
	{
		for (int j = 0; j < p - i - 1; j++)
		{
			if (res[j]>res[j+1])
			{
				swap = res[j];
				res[j] = res[j+1];
				res[j+1] = swap;
			}
		}
	}
}




int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int kase = 0;
	while (scanf("%d%d", &M, &N) == 2)
	{

		if (M == 0 && N == 0)
		{
			break;
		}
		kase++;
		p = 0;

		for (int i = 0; i < N; i++)
		{
			scanf("%s", input[i]);
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{

				if (input[i][j] != '.')
				{
					cnt = 0;
					dfs(i, j);
					res[p++] = cnt;
				}
			}
		}
	

	sort_arr();
	printf("Throw %d\n", kase);
	printf("%d", res[0]);
	for (int i = 1; i < p; i++)
		printf(" %d", res[i]);

	printf("\n\n");
}

	system("PAUSE");
	return 0;
}