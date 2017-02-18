#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector <pair <int, int> > g[100005];
vector <pair <int, int> > gr[100005];
int used[100005];
long long dp[100005][2];

void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
		if (!used[g[v][i].first])
		{
			//cout << v << " " << g[v][i].first << endl;
			gr[v].push_back(make_pair(g[v][i].first, g[v][i].second));
			dfs(g[v][i].first);
		}
}

void f(int v)
{
	if ((int)gr[v].size() == 0)
	{
		dp[v][0] = 0;
		dp[v][1] = 0;
		return;
	}

	long long sum = 0;
	for (int i = 0; i < (int)gr[v].size(); i++)
	{
		f(gr[v][i].first);
		sum += max(dp[gr[v][i].first][0], dp[gr[v][i].first][1]);
	}

	for (int i = 0; i < (int)gr[v].size(); i++)
	{
		dp[v][0] += max(dp[gr[v][i].first][0], dp[gr[v][i].first][1]);
		dp[v][1] = max(dp[v][1], sum - max(dp[gr[v][i].first][0], dp[gr[v][i].first][1]) + dp[gr[v][i].first][0] + 1LL * gr[v][i].second);
	}
	//cout << v << "    " << dp[v][0] << " " << dp[v][1] << endl;
}

int main()
{
	freopen("matching.in", "r", stdin);
	freopen("matching.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		g[x].push_back(make_pair(y, w));
		g[y].push_back(make_pair(x, w));
	}

	dfs(1);
	f(1);

	cout << max(dp[1][0], dp[1][1]) << endl;
	return 0;
}