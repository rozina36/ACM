#include <stdio.h>
#include <stdlib.h>

int N,M;
int grid[102][102];

int checkPlayerOne(int x, int y, int color)
{
	int cnt;
	
	cnt =0;
	for(int i=x ; i<M; i++)
	{
		if(grid[i][y] == color)
		{
			cnt++;
		}
		else
			break;
	}

	for(int i=x-1 ; i>=0; i--)
	{
		if(grid[i][y] == color)
		{
			cnt++;
		}
		else
			break;
	}

	if(cnt ==N)
		return 1;



	cnt =0;
	for(int i= y ; i<M; i++)
	{
		if(grid[x][i] == color)
		{
			cnt++;
		}
		else
			break;
	}

	for(int i=y-1; i>=0; i--)
	{
		if(grid[x][i] == color)
		{
			cnt++;
		}
		else
			break;
	}

	if(cnt ==N)
		return 1;

	cnt =0;
	for(int i=x,j=y; i<M && j<M; i++,j++)
	{
		if(grid[i][j] == color)
		{
			cnt++;
		}
		else
			break;
	}

	for(int i=x-1,j=y-1; i>=0 && j>=0; i--,j--)
	{
		if(grid[i][j] ==color)
		{
			cnt++;
		}
		else
			break;
	}

	if(cnt ==N)
		return 1;

	cnt =0;
	for(int i=x,j=y; i<M && j>=0; j--,i++)
	{
		if(grid[i][j] ==color)
		{
			cnt++;
		}
		else
			break;

	}

	for(int i=x-1,j=y+1; i>=0 && j<M; j++,i--)
	{
		if(grid[i][j] ==color)
		{
			cnt++;
		}
		else
			break;

	}



	if(cnt ==N)
		return 1;

	
 return -1;
}


int main ()
{
int T;
scanf("%d",&T);

while(T--)
{

 scanf("%d %d",&M,&N);
 
 for(int i=0; i<M; i++)
 {
 for(int j=0; j<M; j++)
 {
	 scanf("%d",&grid[i][j]);
 }
 }

int res;
res = -1;
 for(int i=0; i<M; i++)
 {
	 for(int j=0; j<M; j++)
	 {
		 if(grid[i][j] ==1)
		 {
			 if(checkPlayerOne(i,j,1) == 1)
			 {
				 res = 1;
				 break;
			 }
		 }
	 }
 }
 int res2 =-1;

if(res ==-1)
{
	for(int i=0; i<M; i++)
 {
	 for(int j=0; j<M; j++)
	 {
		 if(grid[i][j] == 0){
			 grid[i][j] =2;
		 if(checkPlayerOne(i,j,2) == 1)
		 {
			 res2 = 2;
			 break;
		 }
		 else
			 grid[i][j] =0;
		 }
	 }
 }
}
if(res ==1)
printf("Player 1\n");
else if(res2 ==2)
printf("Player 2\n");
else
printf("-1\n");


}


system("PAUSE");
return 0;
}