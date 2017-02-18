#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define pb push_back

const int N = 200;

int n, k;
int a[N], b[N], c[N];

int was[(1 << 20) + 200];
int ret[(1 << 20) + 200];
bool can[(1 << 20) + 200];


int main()
{
	freopen("meetings.in","r",stdin);
	freopen("meetings.out","w",stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	int maxMask = (1 << n);
	for (int mask = 0; mask < maxMask; mask++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if ((mask & (1 << i)) != 0) {
				sum += c[i];
			}
		}
		ret[mask] = sum;
	}
	for (int mask = 0; mask < maxMask; mask++) {
		was[mask] = -1;
		can[mask] = false;
	}
	can[0] = true;
	for (int mask = 0; mask < maxMask; mask++) {
		if (!can[mask]) continue;
		int value = k + ret[mask];
		for (int i = 0; i < n; i++) {
			if ((mask & (1 << i)) == 0) {
				if (value >= a[i] && value <= b[i]) {
					can[mask + (1 << i)] = true;
					was[mask + (1 << i)] = i;
				}
			}
		}
	}
	int bits = -1;
	int mask_ = 0;
	for (int mask = 0; mask < maxMask; mask++) {
		if (!can[mask]) continue;
		int bb = __builtin_popcount(mask);
		if (bb > bits) {
			bits = bb;
			mask_ = mask;
		}
	}
	int mask = mask_;
	vector<int> ans;
	while (mask > 0) {
		ans.pb(was[mask] + 1);
		mask -= (1 << was[mask]);
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}