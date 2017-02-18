#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector <int> a(30000005);
//int a[30000005];

int kth(int n, int k)
{
	for (int l = 1, r = n; ; )
	{
		
		if (r <= l + 1)
		{
			if (r == l + 1 && a[r] < a[l])
				swap (a[l], a[r]);
			return a[k];
		}
		
		int mid = (l + r) / 2;
		swap (a[mid], a[l + 1]);
		if (a[l] > a[r])
			swap (a[l], a[r]); 
		if (a[l + 1] > a[r])
			swap (a[l + 1], a[r]);
		if (a[l] > a[l + 1])
			swap (a[l], a[l + 1]);
		
		int i = l + 1, j = r;
		int cur = a[l + 1];
		for (;;)
		{
			while (a[++i] < cur) ;
			while (a[--j] > cur) ;
			if (i > j)
				break;
			swap (a[i], a[j]);
		}

		a[l + 1] = a[j];
		a[j] = cur;

		if (j >= k)
			r = j - 1;
		if (j <= k)
			l = i;

	}
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("kth.in", "r", stdin);
	freopen("kth.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	int A, B, C, a1, a2;
	cin >> A >> B >> C >> a1 >> a2;
	a[1] = a1;
	a[2] = a2;
	//a[2] = a[1];

	for (int i = 3; i <= n; i++)
		a[i] = A * a[i - 2] + B * a[i - 1] + C;
		//a[i] = a[1];
	//for (int i = 1; i <= n; i++)
		//cout << a[i] << endl;

	cout << kth(n, k) << endl;

	return 0;
}