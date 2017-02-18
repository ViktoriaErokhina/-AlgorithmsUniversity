#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

pair <long long, long long> st[200505];
long long w[200505];

int main() {
	ios::sync_with_stdio(false);
	//freopen("l.in", "r", stdin);
	//freopen("restructure.out", "w", stdout);
	int n;
	cin >> n;

	long long ans = 0;
	st[0] = make_pair(0, 0);
	for (int i = 1; i <= n; i++)
	{
		long long t, m;
		cin >> t >> m;

		if (m > 0)
		{
			st[i].first = t;
			st[i].second = m;
			w[i] = w[t] + m;
		}
		else
		{
			st[i].first = st[st[t].first].first;
			st[i].second = st[st[t].first].second;
			w[i] = w[st[t].first];
		}
	}

	for (int i = 1; i <= n; i++)
		ans += w[i];

	cout << ans << endl;
	return 0;
}