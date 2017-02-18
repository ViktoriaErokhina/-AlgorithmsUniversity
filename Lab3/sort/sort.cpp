#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

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
		}
	}
}


int main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);

	int n;
	cin >> n;
	vector <int> v;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	merge_sort(v);

	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	return 0;
}