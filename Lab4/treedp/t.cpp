#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define pb push_back

const int N = 300500;

int n;
long long ans[N];
long long ways_down[N], ways_len[N], ways_up[N], ways[N];
vector<int> g[N], num[N];

void dfs_down(int ver, int prev) {
	ways_down[ver] = 1;
	ways_len[ver] = 0;
	for (int i = 0; i < (int)g[ver].size(); i++) {
		int to = g[ver][i];
		if (to == prev) {
			continue;
		}
		dfs_down(to, ver);
		ways_down[ver] += ways_down[to];
		ways_len[ver] += (ways_len[to] + 1LL * ways_down[to]);
	}
}

void dfs_up(int ver, int prev) {
	ways_up[ver] += 1;
	long long all_ways = 0LL;
	long long all_len = 0LL;
	for (int i = 0; i < (int)g[ver].size(); i++) {
		int to = g[ver][i];
		if (to == prev) {
			continue;
		}
		all_ways += ways_down[to];
		all_len += ways_len[to];
	}
	for (int i = 0; i < (int)g[ver].size(); i++) {
		int to = g[ver][i];
		if (to == prev) {
			continue;
		}
		int id = num[ver][i];
		all_ways -= ways_down[to];
		all_len -= ways_len[to];
		ways_up[to] += (all_ways + ways_up[ver]);
		ways[to] += (all_len + 2LL * all_ways + ways_up[ver] + ways[ver]);
		ans[id] = ways[ver] * ways_down[to] + ways_up[ver] * (ways_len[to] + ways_down[to]) + all_len * ways_down[to] + 1LL * all_ways * ways_down[to] + all_ways * (ways_len[to] + ways_down[to]);
		all_ways += ways_down[to];
		all_len += ways_len[to];
		dfs_up(to, ver);
	}
}

void dfs(int ver, int prev) {
	for (int i = 0; i < (int)g[ver].size(); i++) {
		int to = g[ver][i];
		if (to == prev) {
			continue;
		}
		int id = num[ver][i];
		ans[id] = ways[ver] + ways_up[ver] * (ways_len[to] + ways_down[to]);
		dfs(to, ver);
	}
}

int main()
{
	freopen("treedp.in", "r", stdin);
	freopen("treedp.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		num[u].pb(i);
		g[v].pb(u);
		num[v].pb(i);
	}
	dfs_down(1, 1);
	dfs_up(1, 1);
	//dfs(1, 1);
	for (int i = 1; i < n; i++) {
		cout << ans[i];
		puts("");
	}
	return 0;
}