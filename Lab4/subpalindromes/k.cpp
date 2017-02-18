#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const long long MOD = (long long)1e9;
int a[2005];
long long dp[2005][2005];

void f(int l, int r)
{
	if (dp[l + 1][r - 1] == -1)
		f(l + 1, r - 1);
	if (dp[l + 1][r] == -1)
		f(l + 1, r);
	if (dp[l][r - 1] == -1)
		f(l, r - 1);

	dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1] + 3 * MOD;
	if (a[l] == a[r])
		dp[l][r] += dp[l + 1][r - 1] + 1;
	dp[l][r] %= MOD;
}

int main()
{
	//freopen("k.in", "r", stdin);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				dp[i][j] = 1;
			else if (i < j)
				dp[i][j] = -1;

	f(0, n - 1);
	cout << dp[0][n - 1] << endl;
	return 0;
}