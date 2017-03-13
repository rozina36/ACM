#include <stdio.h>
#include <stdlib.h>

int T;
int N, arr[103];
int used[50], per[50],comb[50],comb2[50];
int palindrome[50];
int pal[50], visited[50],visited2[50];

int Ans;
int resF,resF2;
int flag,aflag;

int isVAlid(int start, int end)
{

	if (palindrome[start] == 0 &&  end - start > 1)
	{
		return 0;
	}

	if (end - start > 3)
		return 0;

	int num = 0;

	for (int i = start; i < end; i++)
	{
		num = num * 10 + palindrome[i];
	}

	if (num > 255)
		return 0;


	return 1;

}


int isVAlid2(int start, int end)
{

	if (pal[start] == 0 && end - start > 1)
	{
		return 0;
	}

	if (end - start > 3)
		return 0;

	int num = 0;

	for (int i = start; i < end; i++)
	{
		num = num * 10 + pal[i];
	}

	if (num > 255)
		return 0;


	return 1;

}

void temp()
{
	//printf("\n");

	int i;
	
	if (isVAlid(0, comb[0]) == 0)
	{
		return;
	}

	/*for (i = 0; i < comb[0]; i++)
	{
		printf("%d ", palindrome[i]);

	}
	printf(".");
	*/
	
	if (isVAlid(comb[0],comb[1]) == 0)
	{
		return;
	}
	/*for (i = comb[0]; i < comb[1]; i++)
	{
		printf("%d ", palindrome[i]);
	}
	printf(".");
	*/
	if (isVAlid(comb[1], comb[2]) == 0)
	{
		return;
	}
	/*
	for (i = comb[1]; i < comb[2]; i++)
	{
		printf("%d ", palindrome[i]);
	}
	printf(".");
	*/
	
	if (isVAlid(comb[2], 2*N) == 0)
	{
		return;
	}
	/*for (i = comb[2]; i <2 * N; i++)
	{
		printf("%d ", palindrome[i]);
	}
	printf("\n");
	*/

	Ans++;
}


void temp2()
{
	//printf("\n");

	int i;

	if (isVAlid2(0, comb[0]) == 0)
	{
		return;
	}

	/*for (i = 0; i < comb[0]; i++)
	{
	printf("%d ", pal[i]);

	}
	printf(".");
	*/

	if (isVAlid2(comb[0], comb[1]) == 0)
	{
		return;
	}
	/*for (i = comb[0]; i < comb[1]; i++)
	{
	printf("%d ", pal[i]);
	}
	printf(".");
	*/
	if (isVAlid2(comb[1], comb[2]) == 0)
	{
		return;
	}
	/*
	for (i = comb[1]; i < comb[2]; i++)
	{
	printf("%d ", pal[i]);
	}
	printf(".");
	*/

	if (isVAlid2(comb[2], 2 * N-1) == 0)
	{
		return;
	}
	/*for (i = comb[2]; i <2 * N; i++)
	{
	printf("%d ", pal[i]);
	}
	printf("\n");
	*/

	Ans++;
}


void combi(int index, int start, int limit)
{

	if (index == 3)
	{
		if (limit == 2*N -1)
			temp();
		else if (limit == 2 * N - 2)
			temp2();
		//pr();
		return;
	}

	for (int j = start; j <=limit; j++)
	{
		if (visited[j] == 0)
		{
			visited[j] = 1;
			comb[index] = j;
			combi(index+1,j,limit);
			visited[j] = 0;
		}

	}
}

void print()
{

	for (int i = 0; i < N; i++)
	{
		palindrome[i] = arr[per[i]];
		pal[i] = arr[per[i]];
	}

	for (int i = N - 1, j = N, p = N - 1; i >= 0; i--, j++, p++)
	{
		palindrome[j] = arr[per[i]];
		pal[p] = arr[per[i]];
	}

	combi(0, 1,2*N-1);

	combi(0, 1,2*N-2);

	/*for (int i = 0; i < N+N; i++)
	{
		printf("%d ", palindrome[i]);
	}
	printf("\n");
	

	for (int i = 0; i < N + N -1; i++)
	{
		printf("%d ", pal[i]);
	}
	printf("\n");
	*/
}

void permu(int index)
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
			permu(index + 1);
			used[j] = 0;
		}
	}
}



int main()
{

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d",&N);

		for (int i = 0; i < N; i++)
			scanf("%d",&arr[i]);


		for (int i = 0; i < N; i++){
			used[i] = 0;
			visited[i] = 0;
			visited2[i] = 0;
		}

		Ans = 0;
		permu(0);
		
		printf("%d\n", Ans);

	}

	system("PAUSE");
	return 0;
}