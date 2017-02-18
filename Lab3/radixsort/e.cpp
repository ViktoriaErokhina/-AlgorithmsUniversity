#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
vector <string> s[300];
vector <string> v;
 
int main()
{
    ios::sync_with_stdio(false);
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
 
    int m, n, k;
    cin >> n >> m >> k;
 
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        v.push_back(x);
    }
 
    for (int i = 0; i < k; i++)
    {
        int r = m - i - 1;
        for (int j = 0; j < n; j++)
            s[(int)v[j][r]].push_back(v[j]);
        v.clear();
        for (int j = 0; j < 300; j++)
        {
            for (int q = 0; q < (int)s[j].size(); q++)
                v.push_back(s[j][q]);
            s[j].clear();
        }
    }
 
    for (int i = 0; i < n; i++) 
    {
        cout << v[i] << endl;
    }
     
    return 0;
}
