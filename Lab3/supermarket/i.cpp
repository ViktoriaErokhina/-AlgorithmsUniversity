#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define left aefiojaeoifj
#define right aoeijgaoijeoijawoiajwgoiajwoigjaoijaeoigjaeoigjaeoij

vector <int> v;
int a[100005];
int b[100005];
int t[100005];


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
	a.clear();
	b.clear();
}

int last;
int aa[200000];

void push(int x)
{
	last++;
	int v = last;
	aa[v] = x;

	while (v / 2 > 0 && aa[v / 2] > aa[v])
	{
		swap(aa[v / 2], aa[v]);
		v /= 2;
	}
}

int extract_min()
{
	int ans = aa[1];
	aa[1] = aa[last];

	int pos = 1;
	while (1)
	{
		int f = 0;
		if (pos * 2 + 1 < last && aa[pos] > aa[pos * 2 + 1] && aa[pos * 2 + 1] < aa[pos * 2])
		{
			swap(aa[pos * 2 + 1], aa[pos]);
			pos *= 2;
			pos++;
			f = 1;
		}
		else if (pos * 2 < last && aa[pos] > aa[pos * 2])
		{
			swap(aa[pos * 2], aa[pos]);
			pos *= 2;
			f = 1;
		}
		if (!f)
			break;
	}
	return ans;
}

int main()
{
	//ios::sync_with_stdio(false);
	freopen("supermarket.in", "r", stdin);
	freopen("supermarket.out", "w", stdout);
	int m, n, p;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &a[i], &b[i], &t[i]);
		//cin >> a[i] >> b[i] >> t[i];

	scanf("%d%d", &n, &p);

	long long left = 0, right = (long long)2e10;

	long long ss;
	while (left < right)
	{
		long long mid = (left + right) / 2LL;
		int products = 0;
		last = 0;
		for (int i = 0; i < m; i++)
		{
			if (1LL * mid - t[i] - b[i] >= 0)
			{
				ss = 1LL * mid - t[i] - b[i];
				if (a[i] != 0)
					{
						ss /= (1LL * a[i]);
						ss = min(ss, (long long)(p + 100));
						int to_add = (int)ss;
						to_add = min(to_add, p + 1);
						products += to_add;
						//if (mid == 5) cout << "???"<<i<<":"<<last << endl;
						push(to_add);
						//if (mid == 5) cout << "+" << ":" << i <<":" << last<< endl;
					}
				else
					{
						int to_add = p;
						products += to_add;
						push(to_add);
					}
			}
			//if (mid == 5) {
			//	cout << last << ":" << i << endl;
			//}
			if (last > n) {
				//if (mid == 5) cout << "?" << endl;
				products -= extract_min();
				--last;

			}
			if (products >= p) {
				break;
			}
		}
		if (products >= p)
			right = mid;
		else
			left = mid + 1;
	}

	/*
	for (int i = 0; i < m; i++)
		if (left - t[i] - b[i] > 0)
		{
				v.push_back((left - t[i] - b[i]) / a[i]);
				cout << i << " " << left << " " << t[i] + b[i] << " " << a[i] << endl;
		}

	merge_sort(v);
	int sum = 0;
	for (int i = v.size() - 1; i >= max((int)v.size() - n, 0); i--)
		sum += v[i];
	cout << sum << endl;
	if (sum >= p)
		printf("%d", left);
	else
		printf("%d", right);
	*/
	printf("%I64d\n", left);
	return 0;
}