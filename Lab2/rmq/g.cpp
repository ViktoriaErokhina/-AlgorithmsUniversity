#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ans[300005];
int heap[300005];
vector <int> start[300005];
vector <int> fin[300005];
int seg[300005];
int num_seg_in_heap[300005];
int num_vert_in_seg[300005];
int last;


void push(int ind)
{
	last++;
	heap[last] = seg[ind];
	num_seg_in_heap[ind] = last;
	num_vert_in_seg[last] = ind;

	int pos = last;
	while (pos / 2 > 0 && heap[pos / 2] < heap[pos])
	{
		swap(heap[pos / 2], heap[pos]);
		swap(num_seg_in_heap[num_vert_in_seg[pos / 2]], 
			 num_seg_in_heap[num_vert_in_seg[pos]]);
		swap(num_vert_in_seg[pos / 2], num_vert_in_seg[pos]);
		pos /= 2;
	}
}

void del(int ind)
{
	int num = num_seg_in_heap[ind];
	heap[num] = heap[last];
	swap(num_seg_in_heap[num_vert_in_seg[num]], 
			 num_seg_in_heap[num_vert_in_seg[last]]);
	swap(num_vert_in_seg[num], num_vert_in_seg[last]);
	last--;

	int pos = num;
	if (pos / 2 > 0 && heap[pos] > heap[pos / 2])
	{
		while (pos / 2 > 0 && heap[pos / 2] < heap[pos])
		{
			swap(heap[pos / 2], heap[pos]);
			swap(num_seg_in_heap[num_vert_in_seg[pos / 2]], 
				 num_seg_in_heap[num_vert_in_seg[pos]]);
			swap(num_vert_in_seg[pos / 2], num_vert_in_seg[pos]);
			pos /= 2;
		}
	}
	else
	{
		while (1)
		{
			int f = 0;
			if (pos * 2 + 1 <= last && heap[pos] < heap[pos * 2 + 1] && heap[pos * 2 + 1] > heap[pos * 2])
			{
				swap(heap[pos * 2 + 1], heap[pos]);
				swap(num_seg_in_heap[num_vert_in_seg[pos * 2 + 1]], 
					 num_seg_in_heap[num_vert_in_seg[pos]]);
				swap(num_vert_in_seg[pos * 2 + 1], num_vert_in_seg[pos]);
				pos *= 2;
				pos++;
				f = 1;
			}
			else if (pos * 2 <= last && heap[pos] < heap[pos * 2])
			{
				swap(heap[pos * 2], heap[pos]);
				swap(num_seg_in_heap[num_vert_in_seg[pos * 2]], 
					 num_seg_in_heap[num_vert_in_seg[pos]]);
				swap(num_vert_in_seg[pos * 2], num_vert_in_seg[pos]);
				pos *= 2;
				f = 1;
			}
			if (!f)
				break;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	freopen("rmq.in", "r", stdin);
	freopen("rmq.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		x--;
		y--;

		seg[i] = c;	
		start[x].push_back(i);
		fin[y].push_back(i);
	}

	last = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (int)start[i].size(); j++)
			push(start[i][j]);
		ans[i] = heap[1];
		for (int j = 0; j < (int)fin[i].size(); j++)
			del(fin[i][j]);
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";

	return 0;
}