#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

long long ans = 0;

void merge_sort(vector <int> &v)
{
	if (v.size() == 1)
		return;

	vector <int> a; 
	vector <int> b;

	for (int i = 0; i < (int)v.size() / 2; i++)
		a.push_back(v[i]);
	for (int i = (int)v.size() / 2; i < (int)v.size(); i++)
		b.push_back(v[i]);

	v.clear();
	merge_sort(a);
	merge_sort(b);

	int i = 0, j = 0;

	while (i < (int)a.size() || j < (int)b.size())
	{
		if ((i < (int)a.size() && j < (int)b.size() && a[i] <= b[j]) || j >= (int)b.size())
		{
			v.push_back(a[i]);
			i++;
		}
		else
		{
			v.push_back(b[j]);
			j++;
			ans += a.size() - i;
		}
	}
}

int a, b;
unsigned int cur = 0;
unsigned int nextRand24() 
{
 	cur = cur * a + b;
	return cur >> 8; 
}

int main()
{
	freopen("invcnt.in", "r", stdin);
	freopen("invcnt.out", "w", stdout);

	int n, m;
	cin >> n >> m >> a >> b;
	vector <int> v;

	for (int i = 0; i < n; i++)
		v.push_back(nextRand24() % m);

	merge_sort(v);

	cout << ans << endl;
	return 0;
}