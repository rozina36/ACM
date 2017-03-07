#include <stdio.h>
#include <stdlib.h>


char grid[150][150], edge1[150], edge2[150];
int node, edge, shipment, input[150],graph[150][150],font,rear,Q[50],dp[50],used[50];
int count,minCnt;
int source, dest;

void initpath()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			graph[i][j] = 0;
		}
	}

}

void push(int x)
{

	Q[rear] = x;
	rear++;
}

int pop()
{
	font++;
	return Q[font - 1];
}

int  isEmpty()
{
	if (font >= rear)
		return 1;

	return 0;
}

void initQueue()
{
	rear = 0;
	font = 0;
}


void initUsed()
{
	for (int i = 0; i < node; i++)
		used[i] = 0;
}

void initDP()
{
	for (int i = 0; i < node; i++)
		dp[i] = 0;
}

int strcmp(char str1[], char str2[])
{
	int l = 0;

	for (int i = 0; i < 2; i++)
	{
		if (str1[i] == str2[i])
		{
			l++;
		}
	}

	if (l == 2)
		return 1;
	else
		return 0;
}

int gridIndex(char edge[] )
{
	for (int i = 0; i < node; i++)
	{
		if (strcmp(edge, grid[i]))
			return i;
	}
	return -1;
}


void solveCase()
{

	int x, i;
	count = 0;
	x = source;
	push(x);
	used[x] = 1;
	dp[x] = 0;

	while (!isEmpty())
	{
		x = pop();
		count++;
		for (i = 0; i < node; i++)
		{
			if (!used[i] && graph[x][i])
			{
				used[i] = 1;
				dp[i] = dp[x] + 1;
				if (i == dest)
				{
					if (minCnt > dp[dest])
						minCnt = dp[dest];
				}
				push(i);
			}
		}
	}

}


int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	int kase = 0;
	printf("SHIPPING ROUTES OUTPUT\n");
	while (T--)
	{
		

		scanf("%d%d%d", &node, &edge, &shipment);

		for (int i = 0; i < node; i++)
		{
			scanf("%s", grid[i]);
		}
		initpath();
		for (int j = 0; j < edge; j++)
		{
			scanf("%s", edge1);
			edge1[2] = '\0';
			scanf("%s", edge2);
			edge2[2] = '\0';

			int a, b;
			a = gridIndex(edge1);
			b = gridIndex(edge2);

			graph[a][b] = 1;
			graph[b][a] = 1;
 
		}

		int cost;

		
		printf("\n");
		kase++;
		printf("DATA SET  %d\n", kase);
		printf("\n");

		for (int j = 0; j < shipment; j++)
		{

		
			scanf("%d", &cost);
			scanf("%s", edge1);
			edge1[2] = '\0';
			scanf("%s", edge2);
			edge2[2] = '\0';


			source = gridIndex(edge1);
			dest = gridIndex(edge2);

			//printf("%d %d\n", m,n);


			initQueue();
			initUsed();
			initDP();

			minCnt = 100000;

			solveCase();

			

			if (minCnt == 100000)
				printf("NO SHIPMENT POSSIBLE\n");
			else{
			int res = cost * minCnt * 100;

			printf("$%d\n", res);
		}

		}
	}

	printf("\nEND OF OUTPUT\n");


	//system("PAUSE");
	return 0;
}