#include <stdio.h>
#include <Stdlib.h>

int N, Q;
int input[1003], QR[1003];
int sum, diff[1003], result[1003][1003];

int abss(int a, int b)
{
	if (a>b)
		return a - b;
	else
		return   b - a;
}

void solve()
{
	for (int i = 0; i<N; i++)
	{
		sum = 0;
		for (int j = i + 1; j<N; j++)
		{
			sum = input[i] + input[j];

			for (int k = 0; k<Q; k++)
			{

				if (diff[k]>abss(sum, QR[k])){

					diff[k] = abss(sum, QR[k]);

					result[k][0] = input[i];
					result[k][1] = input[j];

				}

				if (sum == QR[k])
				{
					result[k][0] = input[i];
					result[k][1] = input[j];
				}

			}
		}
	}
}

void initDiff()
{
	for (int i = 0; i<N; i++)
	{
		diff[i] = 10000000;
	}
}

int main()
{
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int kase = 0;
	while (scanf("%d", &N) == 1){
		if (N == 0)
			break;
		kase++;
		printf("Case %d:\n", kase);
		for (int i = 0; i<N; i++)
			scanf("%d", &input[i]);

		scanf("%d", &Q);

		for (int j = 0; j<Q; j++)
			scanf("%d", &QR[j]);

		initDiff();
		solve();

		for (int i = 0; i<Q; i++)
		{
			printf("Closest sum to %d is %d.\n", QR[i], result[i][0] + result[i][1]);
		}
	}

	//system("PAUSE");
	return 0;
}