#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

const long long MOD = 999999937LL;

vector <vector <long long> > matrix(5);

vector <vector <long long> > mult(vector <vector <long long> > a, vector <vector <long long> > b)
{
	vector <vector <long long> > ans = a;
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++) 
		{
			ans[i][j] = 0LL;
		}
	}

	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++) 
		{
			for (int k = 0; k < 5; k++) 
			{
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= MOD;
			}
		}
	}
	return ans;
}

vector <vector <long long> > pow(long long n, vector <vector <long long> > m)
{
	if (n == 1)
		return m;
	if (n % 2 == 1)
	{
		vector <vector <long long> > a = pow(n - 1, m);
		return mult(a, m);
	}
	else
	{
		vector <vector <long long> > a = pow(n / 2, m);
		return mult(a, a);
	}	
}

int main()
{
	freopen("sequences.in", "r", stdin);
	freopen("sequences.out", "w", stdout);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			matrix[i].push_back(1);
	}
	matrix[2][3] = 0;
	matrix[4][3] = 0;
	matrix[2][4] = 0;
	matrix[4][4] = 0;

	while (1)
	{
		long long n;
		cin >> n;
		if (n == 0)
			break;
		if (n == 1)
		{
			cout << 5 << endl;
			continue;
		}
		vector <vector <long long> > v = pow(n - 1, matrix);
		long long sum = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				sum += v[i][j];
				sum %= MOD;
			}
		cout << sum << endl;
	}

	return 0;
}