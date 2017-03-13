#include <stdio.h>
#include <stdlib.h>

int n, A[103], Total, dp[101][50001];

int abss(int a, int b){
	if (a>b)
		return a - b;
	else
		return b - a;
}

int solve(int i, int sum1){

	int sum2, left, right, diff;

	if (dp[i][sum1] >= 0)
	{
		return dp[i][sum1];
	}
	if (i == n){
		sum2 = Total - sum1;
		diff = abss(sum1, sum2);
		dp[i][sum1] = diff;
		return diff;
	}
	left = solve(i + 1, sum1);
	right = solve(i + 1, sum1 + A[i]);

	if (left<right)
	{
		dp[i][sum1] = left;
		return left;
	}
	else
	{
		dp[i][sum1] = right;
		return right;
	}
}

int main()
{
	int t, result;

	scanf("%d", &t);

	for (int j = 0; j<t; j++){
		Total = 0;
		scanf("%d", &n);
		for (int i = 0; i<n; i++){
			scanf("%d", &A[i]);
			//Total = 0;
			Total = Total + A[i];
		}

		for (int k = 0; k<101; k++){
			for (int l = 0; l<50001; l++){
				dp[k][l] = -1;
			}
		}
		result = solve(0, 0);

		printf("%d\n", result);
	}

	system("PAUSE");
	return 0;
}
