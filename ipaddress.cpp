#include <stdio.h>
#include <stdlib.h>

int per[102],comb[102],used[102],input[102],visited[102];
int N,palin[102];
int x,Ans;

int isvalid(int start, int end)
{

	if(palin[start] == 0 && end-start>1)
		return 0;

	if(end - start>3)
		return 0;

	int num =0;

	for(int i=start; i<end; i++)
	{
		num = num *10 + palin[i];
	}

	if(num>255)
		return 0;




	return 1;
}

void printPalin()
{
	for (int i = 0; i < x; i++)
	{
		printf("%d ", palin[i]);
	}
	printf("\n");
}

void do_Something(int n)
{
	/*for (int i = 0; i < comb[0]; i++)
	{
		printf("%d ", palin[i]);
	}
	printf(".");
	*/
	if(isvalid(0,comb[0])== 0)
		return;


	/*for (int j = comb[0]; j < comb[1]; j++)
	{
		printf("%d ", palin[j]);
	}
	printf(".");
	*/
	if(isvalid(comb[0],comb[1])== 0)
		return;
	/*for (int j = comb[1] ; j < comb[2]; j++)
	{
		printf("%d ", palin[j]);
	}
	printf(".");
	*/
	if(isvalid(comb[1],comb[2])== 0)
		return;
	/*for (int j = comb[2]; j < n; j++)
	{
		printf("%d ", palin[j]);
	}
	printf("\n");
*/
	if(isvalid(comb[2],n)== 0)
		return;
	Ans++;
}

void solveComb(int index, int start,int n)
{
	if (index == 3)
	{
		do_Something(n);
		return;
	}

	for (int j = start; j <= n-1; j++)
	{
		if (visited[j] == 0)
		{
			visited[j] = 1;
			comb[index] = j;
			solveComb(index+1,j,n);
			visited[j] = 0;
		}
	}
}

void print()
{
	x = 0;

	for (int i = 0; i < N; i++)
		palin[x++] = input[per[i]];

	for (int i = N-1; i >=0; i--)
	{
		palin[x++] = input[per[i]];
	}
	//printPalin();
	solveComb(0, 1, x);
	x = 0;
	for (int i = 0; i < N; i++)
		palin[x++] = input[per[i]];

	for (int i = N - 2; i >= 0; i--)
	{
		palin[x++] = input[per[i]];
	}
	solveComb(0, 1, x);
	//printPalin();
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
			scanf("%d", &input[i]);

		for (int i = 0; i <2* N; i++){
			used[i] = 0;
			visited[i] =0;
		}
		Ans =0;
		solve(0);
		printf("%d\n", Ans);
		
	}


	//system("PAUSE");
	return 0;
}

