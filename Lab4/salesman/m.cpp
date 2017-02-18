#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const long long INF = 1e18;
long long dp[(1 << 18)][20];
long long gr[20][20];

int main()
{
	freopen("salesman.in", "r", stdin);
	freopen("salesman.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		gr[x][y] = gr[y][x] = w;
	}

	for (int mask = 1; mask < (1 << n); mask++)
		for (int last = 0; last < n; last++)
		{
			dp[mask][last] = INF;
			if (mask == (1 << last))
				dp[mask][last] = 0;
			for (int i = 0; i < n; i++)
				if (i != last && ((mask >> i) & 1) && gr[i][last] > 0)
					dp[mask][last] = min(dp[mask][last], dp[mask ^ (1 << last)][i] + gr[i][last]);
		}

	long long ans = INF;
	for (int i = 0; i < n; i++)
		ans = min(ans, dp[(1 << n) - 1][i]);
	if (ans == INF)
		ans = -1;
	cout << ans << endl;
	return 0;
}