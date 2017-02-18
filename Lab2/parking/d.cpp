#include <iostream>

using namespace std;

int d[300005];

int get(int i)
{
	if (d[i] != i)
		d[i] = get(d[i]);
	return d[i];
}

int main() {
	freopen("parking.in", "r", stdin);
	freopen("parking.out", "w", stdout);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		d[i] = i;
	//cout << "!" << endl;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		x--;

		int t = get(x);
		cout << t + 1 << " ";
		d[t] = (t + 1) % n;
		//cout << d[0] << " " << d[1] << " " << d[2] << endl;
	}

	return 0;
}