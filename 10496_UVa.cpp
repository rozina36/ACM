
#include <stdio.h>
#include <stdlib.h>

int N, M;
int startX,  startY;
int numberOFbeppers;
int arr[103][103];
int per[103],used[103];

int shortestLength;
int tempResult;
int p = 0;

int abss(int a, int b)
{

    if(a>b)
        return a -b;
    else
        return b - a;

}

void print()
{
	int diff =0;
		diff = abss(startX,arr[per[0]][0]) + abss(startY, arr[per[0]][1]);
		for(int i=1;  i<numberOFbeppers; i++){
		 diff = diff + abss(arr[per[i-1]][0],arr[per[i]][0])+ abss(arr[per[i-1]][1],arr[per[i]][1]);
		}
		diff = diff + abss(startX,arr[per[numberOFbeppers-1]][0]) + abss(startY, arr[per[numberOFbeppers-1]][1]);

	if (shortestLength > diff)
		shortestLength = diff;
}

void solve(int index)
{
	if (index == numberOFbeppers)
	{
		print();
		return;
	}

	for (int i = 0; i < numberOFbeppers; i++)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			per[index] = i;
			solve(index + 1);
			used[i] = 0;
		}
	}

}



int main()
{

	int T;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d", &N, &M);
		scanf("%d%d", &startX, &startY);
		scanf("%d", &numberOFbeppers);

		for (int i = 0; i < numberOFbeppers; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				scanf("%d", &arr[i][j]);
			}

		}
		for (int i = 0; i < numberOFbeppers; i++)
			used[i] = 0;
		shortestLength = 1000000;
		solve(0);

		printf("The shortest path has length %d\n", shortestLength);
	}

	return 0;
}

