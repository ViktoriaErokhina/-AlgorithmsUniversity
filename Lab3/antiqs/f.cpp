#include <iostream>
#include <stdio.h>
using namespace std;

int a[70005];

int main()
{
	freopen("antiqs.in", "r", stdin);
	freopen("antiqs.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	for (int i = 2; i < n; i++)
		swap(a[i], a[i / 2]);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
