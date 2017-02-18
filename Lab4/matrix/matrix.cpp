#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

pair <long long, long long> p[500];
long long dp[500][500];
int open[500];
int closed[500];

void f(int l, int r)
{
	//cerr << l << " " << r << endl;
	if (r - l == 1)
	{
		dp[l][r] = p[l].first * p[l].second * p[r].second;
		return;
	}

	//int k = 0;
	long long sum = (long long)1e17;
	for (int i = l; i < r; i++) // 0..1
	{
		if (dp[l][i] == -1)
			f(l, i);
		if (dp[i + 1][r] == -1)
			f(i + 1, r);

		//cout << l << " " << i << "   " << i + 1 << " " << r << endl;
		//cout << dp[l][i] << " " << dp[i + 1][r] << endl << endl;

		long long sum0 = dp[l][i] + dp[i + 1][r] + p[l].first * p[i + 1].first * p[r].second;
		if (sum0 < sum)
		{
			sum = sum0;
			//k = i;
		}
	}
	dp[l][r] = sum;
	/*
	if (k == l)
	{
		//open[l]++;
		closed[r] += 1;
		open[k + 1]++;
	}
	else if (k + 1 == r)
	{
		open[l] += 1;
		//closed[r]++;
		closed[k]++;
	}
	else
	{
		open[l] += 1;
		closed[r] += 1;
		closed[k]++;
		open[k + 1]++;
	}
	*/
}

void ans(int l, int r)
{
	if (l == r)
		return;
	open[l]++;
	closed[r]++;
	if (l == r - 1)
		return;
	int k = 0;
	long long sum = (long long)1e17;
	for (int i = l; i < r; i++) 
	{
		long long sum0 = dp[l][i] + dp[i + 1][r] + p[l].first * p[i + 1].first * p[r].second;
		if (sum0 < sum)
		{
			sum = sum0;
			k = i;
		}
	}
	ans(l, k);
	ans(k + 1, r);
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				dp[i][j] = -1;

	f(0, n - 1);
	ans(0, n - 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < open[i]; j++)
			cout << "(";
		cout << "A";
		for (int j = 0; j < closed[i]; j++)
			cout << ")";
	}
	cout << endl;
	//cout << dp[0][n - 1];
	return 0;
}