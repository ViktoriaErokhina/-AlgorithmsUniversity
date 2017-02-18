#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int f[2005];
int g[2005];
set <pair <int, int> > s;
string code[2005];
int lef[2005];
int rig[2005];

void rec(int k, string c)
{
	if (lef[k] == -1)
	{
		code[k] = c;
		//cout << k << " " << c << endl;
		return;
	}

	c += '0';
	rec(lef[k], c);
	c[c.size() - 1] = '1';
	rec(rig
	[k], c);
	//c.erase(c.size() - 1, 1);
}

int main()
{
	freopen("optimalcode.in", "r", stdin);
	//freopen("optimalcode.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> f[i];
		g[i] = f[i];
		s.insert(make_pair(f[i], i));
		lef[i] = -1;
		rig
	[i] = -1;
	}
	int cnt = n;
	while (s.size() > 1)
	{
		pair <int, int> a, b;
		a = *(s.begin());
		s.erase(a);
		b = *(s.begin());
		s.erase(b);
		if (a.second > b.second) {
			swap(a, b);
		}
		g[cnt] = a.first + b.first;
		s.insert(make_pair(g[cnt], cnt));
		lef[cnt] = a.second;
		rig
	[cnt] = b.second;
		cnt++;
	}
	pair <int, int> a;
	a = *(s.begin());
	string c = "";
	rec(a.second, c);

	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += f[i] * code[i].size();
	cout << sum << endl;
	for (int i = 0; i < n; i++)
		cout << code[i] << endl;
	return 0;
}