#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a[600005];
int num[600005];
int mm[600005];

void push(int last, int x)
{
	last++;
	a[last] = x;

	while (last / 2 > 0 && a[last / 2] > a[last])
	{
		swap(a[last / 2], a[last]);
		swap(num[mm[last / 2]], num[mm[last]]);
		swap(mm[last / 2], mm[last]);
		last /= 2;
	}
}

void decrease(int pos, int x)
{
	a[pos] = x;
	while (pos / 2 > 0 && a[pos / 2] > a[pos])
	{
		swap(a[pos / 2], a[pos]);
		swap(num[mm[pos / 2]], num[mm[pos]]);
		swap(mm[pos / 2], mm[pos]);
		pos /= 2;
	}
}

int extract_min(int last)
{
	int ans = a[1];
	a[1] = a[last];
	num[mm[last]] = 1;
	mm[1] = mm[last];

	int pos = 1;
	while (1)
	{
		int f = 0;
		if (pos * 2 + 1 < last && a[pos] > a[pos * 2 + 1] && a[pos * 2 + 1] < a[pos * 2])
		{
			swap(a[pos * 2 + 1], a[pos]);
			swap(num[mm[pos * 2 + 1]], num[mm[pos]]);
			swap(mm[pos * 2 + 1], mm[pos]);
			pos *= 2;
			pos++;
			f = 1;
		}
		else if (pos * 2 < last && a[pos] > a[pos * 2])
		{
			swap(a[pos * 2], a[pos]);
			swap(num[mm[pos * 2]], num[mm[pos]]);
			swap(mm[pos * 2], mm[pos]);
			pos *= 2;
			f = 1;
		}
		if (!f)
			break;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	freopen("priorityqueue.in", "r", stdin);
	freopen("priorityqueue.out", "w", stdout);

	int last = 0;
	int cnt = 0;
	string s;
	while (cin >> s)
	{
		cnt++;
		if (s[0] == 'p')
		{
			int x;
			cin >> x;
			num[cnt] = last + 1;
			mm[num[cnt]] = cnt;
			push(last, x);
			//mm[num[cnt]] = cnt;
			last++;
		}
		else if (s[0] == 'd')
		{
			int x, y;
			cin >> x >> y;
			//cout << "num = " << num[x] << endl;
			decrease(num[x], y);
		}
		else
		{
			if (last == 0)
				cout << "*" << endl;
			else
			{
				cout << extract_min(last) << endl;
				last--;
			}
		}
		//cerr << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " 
			//<< a[5] << endl;
	}

	return 0;
}

/*
push 4
push 5
push 1
push 2
push 1
decrease-key 4 1
extract-min
extract-min
extract-min
extract-min
*/