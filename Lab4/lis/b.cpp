#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int INF = 2 * 1e9;
int a[300005];
set <pair <int, int> > s;
int dp[300005];
vector <int> ans;
int pr[300005];
int num[300005];

int main()
{
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
		dp[i] = INF;

	int cnt = 1;
	s.insert(make_pair(-INF, 0));
	num[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		pair <int, int> v = make_pair(a[i], -INF);
		if (s.upper_bound(v) == s.end())
		{
			dp[cnt] = a[i];
			num[cnt] = i;
			s.insert(make_pair(a[i], cnt));
			pr[i] = num[cnt - 1];
			cnt++;
			//cout << i << "    " << cnt - 1 << endl;
		}
		else
		{
			pair <int, int> p = *(s.upper_bound(v));
			//cout << i << "    " << p.first << " " << p.second << endl;
			s.erase(p);
			p.first = a[i];
			s.insert(p);
			dp[p.second] = a[i];
			num[p.second] = i;
			pr[i] = num[p.second - 1];
		}	
	}
	cout << cnt - 1 << endl;
	int k = num[cnt - 1];
	while (k != -1)
	{
		ans.push_back(a[k]);
		k = pr[k];
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}