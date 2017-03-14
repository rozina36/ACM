/*#include <stdio.h>
#include <stdlib.h>

int T;
int N, H, W;
int board[50][50];

void copyArr(int b[][50], int a[][50])
{

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void fill(int b[][50], int x, int y)
{
	b[x][y] = 0;
	if (b[x][y] > 1)
	{
		for (int k = b[x][y]-1; k>=1; k--){
			
			if (x-k> 0)
			{
				fill(b, x - k, y);
			}
			if (y-k > 0){
				fill(b, x, y - k);
			}
			if (x+k < H){
				fill(b, x + k, y);
			}
			if (y+k< W){
				fill(b, x, y + k);
			}
		}
	}
}

void boardchange(int a[][50])
{
	for (int j = 0; j < W; j++)
	{
		for (int i = 0; i < H; i++)
		{
			if (a[i][j] == 0)
			{
				int k, p;

				for (k = i; k > 0; k--)
				{
					if (a[k][j] != 0){
						a[i][j] = a[k][j];
						a[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}

int c;

void solve(int level, int a[][50])
{
	if (level == N)
	{
		for (int p = 0; p < H; p++)
		{
			for (int q = 0; q < W; q++)
			{
				if (a[p][q] > 0)
					c++;
			}
		}

		return;
	}
	
	int i, j, k, l;
	int b[50][50];
	copyArr(b, a);

	for ( i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		 if (b[i][j])
			{
				fill(b, i, j);
			}
			boardchange(b);
			solve(level + 1, b);
			copyArr(b, a);
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	scanf("%d%d%d",&N, &H, &W);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	c = 0;

	solve(0,board);
	//boardchange(board);
	printf("%d\n", c);
	

	return 0;
}


*/

#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 16
int Ans;

int T;
int N, W, H;
int block[MAX_SIZE][MAX_SIZE];
int Case;

void printArray(int a[][MAX_SIZE])
{
	int i, j;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++){
			printf("%4d", block[i][j]);
		}
		printf("\n");
	}
}

void fill(int a[][MAX_SIZE], int x, int y)
{
	int i, temp;
	if (0 == a[x][y])
		return;

	temp = a[x][y];
	a[x][y] = 0;
	
	for (i = 1; i <temp ; i++)
	{
		if (x - i >= 0)
			fill(a, x - i, y);
		if (x + i < H)
			fill(a, x + i, y);
		if (y - i >= 0)
			fill(a, x, y - i);
		if (y + i < W)
			fill(a, x, y + i);
	}
}

void copyArr(int b[][MAX_SIZE], int a[][MAX_SIZE])
{

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void update(int a[][MAX_SIZE])
{

	int i, j, k;
	for (i = H - 1; i >= 0; i--)
	{
		for (j = 0; j < W; j++)
		{
			if (0 == a[i][j])
			{
				for (k = i - 1; k >= 0; k--)
					if (a[k][j] != 0)
					{
						a[i][j] = a[k][j];
						a[k][j] = 0;
						break;
					}
			}

		}
	}
}




int countBlock(int a[][MAX_SIZE])
{
	int i, j;
	int count;
	count = 0;

	for ( i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			if (a[i][j] > 0)
				count++;
		}
	}

	return count;
}
void solve(int level, int parent[][MAX_SIZE])
{
	int i, j;
	int cnt;
	int child[MAX_SIZE][MAX_SIZE];

	if (level == N){
		cnt = countBlock(parent);
		if (Ans > cnt)
			Ans = cnt;
		return;
	}
	for (j = 0; j < W; j++)
	{
		copyArr(child, parent);

		for (i = 0; i < H; i++){
			if (child[i][j])
				break;
		}
			fill(child, i, j);
			update(child);
			solve(level + 1, child);
	}
}

void solveCase()
{
	Ans = W*H;
	solve(0, block);
}

void readCase()
{
	scanf("%d %d %d", &N, &W, &H);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			scanf("%d", &block[i][j]);
		}
	}
}


int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	while (T--){
		readCase();
		solveCase();
		printf("%d\n", Ans);
	}
}
