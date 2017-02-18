#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int INF = 239239239;

bool dp[10005][10005];

int main()
{
	//freopen("f.in", "r", stdin);

	string s, c;
	cin >> s >> c;
	int n = s.size();
	int m = c.size();

	c += "&";

	dp[0][0] = true;
	int f = INF;
	for (int i = 0; i < n; i++)
	{
		int f0 = INF;

		for (int j = 0; j <= m; j++)
		{
			if (j >= f)
				dp[i][j] = true;
			//cout << i << " " << j << "    " << dp[i][j] << endl;
			if (!dp[i][j])
				continue;
			if (s[i] == c[j])
				dp[i + 1][j + 1] = true;
			if (s[i] == '?')
				dp[i + 1][j + 1] = true;
			if (s[i] == '*')
				f0 = min(f0, j);
			//cout << i << " " << j << "    " << dp[i][j] << endl;
		}
		//if (s[i] == '*' && dp[i][m]) dp[i + 1][m] = true;
		f = f0;
	}
	for (int j = 0; j <= m; j++) 
	{
		if (j >= f) 
		{
			dp[n][j] = true;
		}
		//cout << n << " " << j << "    " << dp[n][j] << endl;
	}

	int g1 = 1;
	for (int i = 0; i < n; i++)
		if (s[i] != '*')
			g1 = 0; 
	if (g1 && m == 0)
	{
		cout << "YES" << endl;	
		//cout << "!";
	}
	else if (n == 0 && m == 0)
		cout << "YES" << endl;
	else if (dp[n][m])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}