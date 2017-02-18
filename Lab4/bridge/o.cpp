#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int dp[155][155];

int main()
{
	freopen("bridge.in", "r", stdin);
	freopen("bridge.out", "w", stdout);
	int x, a, y, b, l;
	cin >> x >> a >> y >> b >> l;

	int lef = 1, rig = x * a + y * b + 2;
	while (rig - lef > 1)
	{
		int mid = (lef + rig) / 2;

		int ans = 0;
		for (int i = 0; i <= x; i++)
			for (int j = 0; j <= y; j++) {
				dp[i][j] = 0;
				for (int k = 0; k <= i; k++)
				{
					/*
					if (i - 1 >= 0) {
						dp[i][j] = max(dp[i][j], dp[i - 1][j]);
					}
					if (j - 1 >= 0) {
						dp[i][j] = max(dp[i][j], dp[i][j - 1]);
					}*/
					int rem = mid - k * a;
					rem = max(rem, 0);
					int m =	rem / b;
					if (rem % b != 0)
						m++;
					if(j >= m)
						dp[i][j] = max(dp[i][j], dp[i - k][j - m] + 1);	
					ans = max(ans, dp[i][j]);	
				}
			}
		for (int i = 0; i <= x; i++)
			for (int j = 0; j <= y; j++)
				dp[i][j] = 0;

		//cout << mid << " " << ans << endl;
		if (ans < l)
			rig = mid;
		else
			lef = mid;
	}
	cout << lef << endl;
	return 0;
}