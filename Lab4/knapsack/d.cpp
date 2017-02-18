#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1005][100005];
int f[1005][100005];
int m[1005];
int c[1005];
vector <int> ans;

int main()
{
	freopen("knapsack.in", "r", stdin);
	freopen("knapsack.out", "w", stdout);

	int n, M;
	cin >> n >> M;

	for (int i = 1; i <= n; i++)
		cin >> m[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= M; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= m[i])
			{
				int a = dp[i][j], b = dp[i - 1][j - m[i]] + c[i];
				if (a < b)
				{
					dp[i][j] = b;
					f[i][j] = 1;
				}
			}
		}

	int k = n, h = M;
	while (k > 0)
	{
		//cout << k << " " << h << endl;
		if (f[k][h])
		{
			ans.push_back(k);
			h -= m[k];
			k--;
		}
		else
			k--;
	}
	sort(ans.begin(), ans.end());
	cout << (int)ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}