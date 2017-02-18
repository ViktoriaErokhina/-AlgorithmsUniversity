#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
pair <int, int> p[100005];
 
 int n, k;
vector <pair <double, int> > v;
vector <int> ans;


int last;
pair <double, int> aa[200000];


void push(pair <double, int> x)
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

pair <double, int> extract_min()
{
    pair <double, int> ans = aa[1];
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

void heap_sort(vector <pair <double, int> > &v)
{
    last = 0;
    int r = v.size();
    for (int i = 0; i < r; i++) {
        push(v[i]);
        if (last > k) {
            extract_min();
            --last;
        }
    }
    v.clear();
    for (;;)
    {
        v.push_back(extract_min());
        last--;
        if (last == 0) break;
    }
}


 
int main()
{
    freopen("kbest.in", "r", stdin);
    freopen("kbest.out", "w", stdout);
 
    cin >> n >> k;
 
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
 
 
    double left = 0, right = (double)1e8;
 
    int cnt = 0;
    while (cnt < 50)
    {
        double mid = (left + right) / 2;
 
        for (int i = 0; i < n; i++)
            v.push_back(make_pair(p[i].first - p[i].second * mid, i + 1));
        heap_sort(v);
        double sum = 0;
        for (int i = 0; i < (int)v.size(); i++)
            sum += v[i].first;
        if (sum >= 0)
        {
            left = mid;
            ans.clear();
            for (int i = 0; i < (int)v.size(); i++)
                ans.push_back(v[i].second);
        }
        else
            right = mid;
        v.clear();
        cnt++;
    }
 
    double mid = left;
    for (int i = 0; i < n; i++)
            v.push_back(make_pair(p[i].first - p[i].second * mid, i + 1));
        heap_sort(v);
        double sum = 0;
        for (int i = 0; i < (int)v.size(); i++)
            sum += v[i].first;
        if (sum >= 0)
        {
            left = mid;
            ans.clear();
            for (int i = 0; i < (int)v.size(); i++)
                ans.push_back(v[i].second);
        }
 
    //sort(ans.begin(), ans.end());
 
    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";
 
    return 0;
}