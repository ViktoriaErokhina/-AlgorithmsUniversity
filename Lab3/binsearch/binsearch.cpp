#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

long long a[100005];

int main()
{
	ios::sync_with_stdio(false);
	freopen("binsearch.in", "r", stdin);
	freopen("binsearch.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;

		int left = -1, right = n - 1;

		while (right - left > 1)
		{
			int mid = (left + right) / 2;

			if (a[mid] >= x)
				right = mid;
			else
				left = mid;
		}
		if (a[right] == x)
			cout << right + 1 << " ";
		else
		{
			cout << "-1 -1" << endl;
			continue;
		}

		left = 0, right = n;

		while (right - left > 1)
		{
			int mid = (left + right) / 2;

			if (a[mid] > x)
				right = mid;
			else
				left = mid;
		}
		cout << left + 1 << endl;
	}

	return 0;
}