#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define F first
#define S second
vector <pair <string, pair <int, int> > > v;
vector <string> ans;
int d[200005];
int r[200005];

int d2[300005];
 
int get2(int i)
{
    if (d2[i] != i)
        d2[i] = get2(d2[i]);
    return d2[i];
}


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
	freopen("restructure.in", "r", stdin);
	freopen("restructure.out", "w", stdout);
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		d[i] = i;
		d2[i] = i;
	}

	for (int i = 0; i < q; i++)
	{
		int a, x, y;
		cin >> a >> x >> y;

		if (a == 3)
		{
			if (get(x) == get(y))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if (a == 1)
		{
			update(x, y);
			/*
			int x0 = min(x, y);
			int y0 = max(x, y);
			int t = get2(x0);
			int h = get2(y0);
			if (t != h)
			{
				if (t < h)
					d2[t] = h;
				else
					d2[h] = t;
			}
			*/
		}
		else
		{
			for (int j = x; j < y; j++)
			{
				int t = get2(j);
				if (t < y)
				{
					d2[t] = t + 1;
					update(t, t + 1);
					j = t;
				}
				else
					break;
			}
		}
	}

	return 0;
}