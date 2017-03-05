#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996);

int N, M;
int startX, startY;
int numberOFbeppers;
int arr[103][103];
int vis[103][103];
int per[103], used[103];
int shortestLength;
int ultimateShortest;
int val;

void flodfill(int x, int y, int destX, int destY, int res)
{
    vis[x][y]=res;
    
    if (res > shortestLength)
        return;

    if (x == destX && y == destY)
    {
        if (shortestLength>res)
            shortestLength = res;

        return;
    }

    if (x > 0 && vis[x-1][y]>res+1)
        flodfill(x - 1, y, destX, destY, res + 1);

    if (x < N - 1 && vis[x+1][y]>res+1)
        flodfill(x + 1, y, destX, destY, res + 1);

    if (y > 0 && vis[x][y-1]>res+1)
        flodfill(x, y - 1, destX, destY, res + 1);

    if (y < N - 1 && vis[x][y+1]>res+1)
        flodfill(x, y + 1, destX, destY, res + 1);
}

void print()
{
    int cnt;
    int total = 0;

    for (int i = 0; i <= numberOFbeppers; i++)
    {
        printf("%d\n", per[i]);

        shortestLength = 1000000;

        for (int k = 0; k < N; k++)
            for (int j = 0; j < M; j++)
                vis[k][j] = shortestLength;

        if (i == 0)
            flodfill(startX, startY, arr[per[i]][0], arr[per[i]][1], 0);
        else if (i <= numberOFbeppers - 1)
            flodfill(arr[per[i-1]][0], arr[per[i-1]][1], arr[per[i]][0], arr[per[i]][1], 0);
        else
            flodfill(arr[per[i-1]][0], arr[per[i-1]][1], startX, startY, 0);

        printf("shortestLength %d\n", shortestLength);

        total += shortestLength;
    }
    
    if (total < ultimateShortest)
    {
        ultimateShortest = total;
    }
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

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                vis[i][j] = 0;

        for (int i = 0; i < numberOFbeppers; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        for (int i = 0; i < numberOFbeppers; i++)
            used[i] = 0;

        ultimateShortest = 1000000;
        
        solve(0);

        printf("%d\n", ultimateShortest);
    }

    system("PAUSE");

    return 0;
}