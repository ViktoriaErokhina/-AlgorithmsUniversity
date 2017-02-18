#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

const double Eps = 1e-6;
const double eps = 1e-6;

int main()
{
	freopen("garland.in", "r", stdin);
	freopen("garland.out", "w", stdout);

	int n;
	double A;
	cin >> n >> A;

	double left = 0, right = A;
	while (right - left > Eps)
	{
		double mid = (right + left) / 2;

		double B = (n - 1) * mid - (n - 2) * A + n * (n - 3) + 2; 
		double minf = min(min(A, B), mid);
		int n0 = (int)(A + 1 - mid) / 2;
		if (2 <= n0 && n0 <= n - 2)
			minf = min(minf, n0 * mid - (n0 - 1) * A + n0 * (n0 - 1));
		if (2 <= n0 + 1 && n0 + 1 <= n - 2)
			minf = min(minf, (n0 + 1) * mid - n0 * A + n0 * (n0 + 1));
		if (2 <= n0 - 1 && n0 - 1 <= n - 2)
			minf = min(minf, (n0 - 1) * mid - (n0 - 2) * A + (n0 - 2) * (n0 - 1));
		//cout << mid << " " << minf << endl;
		if (minf < eps)
			left = mid;
		else
			right = mid;
		//cout << minf << endl;
	}

	double mid = left;
	//double mid = 8;
	double B = (n - 1) * mid - (n - 2) * A + n * (n - 3) + 2; 
	cout.precision(4);
	cout << fixed << B << endl;

	return 0;
}
/*
0  1 2 3 4
15 8 3 0 -1 0 3 8
a[4] = 2 * 0 - 3 + 2 = -1
a[5] = 2 * -1 - 0 + 2 = 0
a[6] = 2 * 0 + 1 + 2 = 3
*/