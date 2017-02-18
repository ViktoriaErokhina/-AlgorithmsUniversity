#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define F first
#define S second
vector <pair <string, pair <int, int> > > v;
vector <string> ans;
int d[50005];
int r[50005];

int get(int i)
{
	if (d[i] != i)
		d[i] = get(d[i]);
	return d[i];
}

void update(int x, int y)
{
	if (get(x) == get(y))
		return;
	int f = 0;
	if (r[get(x)] > r[get(y)])
		swap(x, y);
	else if (r[get(x)] == r[get(y)])
		f = 1;
	d[get(y)] = get(x);
	r[get(y)] += f;
}

int main() {
	ios::sync_with_stdio(false);
	freopen("cutting.in", "r", stdin);
	freopen("cutting.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
	}
	for (int i = 0; i < k; i++)
	{
		string s;
		int x, y;
		cin >> s >> x >> y;
		x--; y--;
		v.push_back(make_pair(s, make_pair(x, y)));
	}
	reverse(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		d[i] = i;
		r[i] = 0;
	}

	for (int i = 0; i < k; i++)
	{
		int x = v[i].S.F;
		int y = v[i].S.S;
		if (v[i].F[0] == 'a')
		{
			if (get(x) == get(y))
				ans.push_back("YES");
			else
				ans.push_back("NO");
		}
		else
		{
			update(x, y);
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}