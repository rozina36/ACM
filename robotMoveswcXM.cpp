// doublePlayerDestinationGame.cpp : Defines the entry point for the console application.
#include<stdio.h>
#include <stdlib.h>
#define SIZE 15
#define INF 214748364
int R,C, Max;
int Grid[SIZE][SIZE];

int M, xIndex[SIZE], yIndex[SIZE], directionArray[SIZE], directionArrayFinal[SIZE];

void input()
{
	Max = INF;
	scanf("%d%d", &R,&C);
	int i, j;
	for (i = 0; i<R; i++)
		for (j = 0; j<C; j++)
			scanf("%d", &Grid[i][j]);
}

void dfs(int row1, int col1, int row2, int col2, int count, int direction)
{
	directionArray[count] = direction;
	//printf("%d%d %d%d\n", row1, col1, row2, col2);
	if (count == 9)
	{
		//printf("More than Eight\n");
		return;
	}
	if (Grid[row1][col1] == -1 && Grid[row2][col2] == -2)
	{
		//printf("Reached in count %d\n",count);
		if (count <= Max)
		{
			int i;
			for (i = 1; i <= count; i++)
				directionArrayFinal[i - 1] = directionArray[i];
			Max = count;
		}
		return;
	}

	// move RIGHT
	int r1, c1, r2, c2;

	r1 = row1; r2 = row2; c1 = col1; c2 = col2;
	if (col1>col2)
	{
		while (col1++<C - 1 && Grid[row1][col1] != 9);
		col1--;

		while (col2++<C - 1 && Grid[row2][col2] != 9 && (row1 != row2 || col1 != col2));
		col2--;
		dfs(row1, col1, row2, col2, count + 1, 2);
	}
	else
	{
		while (col2++<C - 1 && Grid[row2][col2] != 9);
		col2--;

		while (col1++<C - 1 && Grid[row1][col1] != 9 && (row1 != row2 || col1 != col2));
		col1--;
		dfs(row1, col1, row2, col2, count + 1, 2);
	}
	row1 = r1; col1 = c1; row2 = r2; col2 = c2;

	// move DOWN
	if (row1>row2)
	{
		while (row1++<R - 1 && Grid[row1][col1] != 9);
		row1--;

		while (row2++<R - 1 && Grid[row2][col2] != 9 && (row1 != row2 || col1 != col2));
		row2--;
		dfs(row1, col1, row2, col2, count + 1, 4);
	}
	else
	{
		while (row2++<R - 1 && Grid[row2][col2] != 9);
		row2--;

		while (row1++<R - 1 && Grid[row1][col1] != 9 && (row1 != row2 || col1 != col2));
		row1--;
		dfs(row1, col1, row2, col2, count + 1, 4);
	}
	row1 = r1; col1 = c1; row2 = r2; col2 = c2;

	// move LEFT
	if (col1<col2)
	{
		while (col1-->0 && Grid[row1][col1] != 9);
		col1++;

		while (col2-->0 && Grid[row2][col2] != 9 && (row1 != row2 || col1 != col2));
		col2++;
		dfs(row1, col1, row2, col2, count + 1, 1);
	}
	else
	{
		while (col2-->0 && Grid[row2][col2] != 9);
		col2++;

		while (col1-->0 && Grid[row1][col1] != 9 && (row1 != row2 || col1 != col2));
		col1++;
		dfs(row1, col1, row2, col2, count + 1, 1);
	}
	row1 = r1; col1 = c1; row2 = r2; col2 = c2;

	// move UP
	if (row1<row2)
	{
		while (row1-->0 && Grid[row1][col1] != 9);
		row1++;

		while (row2-->0 && Grid[row2][col2] != 9 && (row1 != row2 || col1 != col2));
		row2++;
		dfs(row1, col1, row2, col2, count + 1, 3);
	}
	else
	{
		while (row2-->0 && Grid[row2][col2] != 9);
		row2++;

		while (row1-->0 && Grid[row1][col1] != 9 && (row1 != row2 || col1 != col2));
		row1++;
		dfs(row1, col1, row2, col2, count + 1, 3);
	}
}


int main()
{
	int i, test_case, T, j, r1, c1, r2, c2;

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &test_case);
	for (T = 1; T <= test_case; T++)
	{
		// make initial 1 and 2 grid 0
		input();
		for (i = 0; i<R; i++)
		{
			for (j = 0; j<C; j++)
			{
				if (Grid[i][j] == 1)
				{
					r1 = i;
					c1 = j;
				}
				else if (Grid[i][j] == 2)
				{
					r2 = i;
					c2 = j;
				}
			}
		}
		Grid[r1][c1] = 0;
		Grid[r2][c2] = 0;
		dfs(r1, c1, r2, c2, 0, 0);
		if (Max == INF)
			printf("Milbena Mahtab\n");
		else
		{
			printf("Mahtab count = %d\n", Max);

			/*for (i = 0; i<Max; i++)
			{
				if (directionArrayFinal[i] == 1)
					printf("Left\n");
				else if (directionArrayFinal[i] == 2)
					printf("Right\n");
				else if (directionArrayFinal[i] == 3)
					printf("Up\n");
				else
					printf("Down\n");
			}
			*/
		}
	}

	system("PAUSE");
	return 0;
}

