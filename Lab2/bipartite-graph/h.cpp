#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int d[300005];
int r[300005];
bool col[300005];
bool change[300005];
 
 
pair <int, int> get(int x)
{
        if (d[x] == x)
                return(make_pair(x, col[x]));
 
        pair <int, int> p = get(d[x]);
        //p.second ^= col[x];
        /*
        int i = x;
        while (d[i] != i)
                i = d[i];
        */
        return make_pair(p.first, (p.second ^ col[x]));
}
 
void unite(int x, int y)
{
        //if (get(x).first == get(y).first)
                //return;
 	
 		int f = 0;
        if (r[get(x).first] > r[get(y).first])
                swap(x, y);
        if (r[get(x).first] == r[get(y).first])
        	f = 1;
 
        int c1 = get(x).second;
        int c2 = get(y).second;
        if (c1 == c2)
        {
                col[x] ^= 1;
        }
        d[get(x).first] = get(y).first;
        r[get(y).first] += f;
}
 
 
int main() {
        ios::sync_with_stdio(false);
        //freopen("h.in", "r", stdin);
        //freopen("rmq.out", "w", stdout);
        int n, m;
        cin >> n >> m;
 
        for (int i = 1; i <= n; i++)
                d[i] = i;
 
        int sh = 0;
        for (int i = 0; i < m; i++)
        {
                int cc, a, b;
                cin >> cc >> a >> b;
 
                if (cc == 0)
                {
                        int x = (a + sh) % n;
                        if (x == 0)
                                x = n;
                        int y = (b + sh) % n;
                        if (y == 0)
                                y = n;
                        //cout << "un: " << x << " " << y << endl;
                        unite(x, y);
                        //cout << "col: " << col[1] << " " << col[2] << " " << col[3] << " " << col[4] << endl;
                        //cout << "change: " << change[1] << " " << change[2] << " " << change[3] << " " << change[4] << endl;
                        //cout << "d: " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << endl;
                        //cout << endl;
                }
                else
                {
                        int x = (a + sh) % n;
                        if (x == 0)
                                x = n;
                        int y = (b + sh) % n;
                        if (y == 0)
                                y = n;
 
                        //cout << "check: " << x << " " << y << endl;
 
                        int c1 = get(x).second;
                        int c2 = get(y).second;
                        //cout << "col: " << col[1] << " " << col[2] << " " << col[3] << " " << col[4] << endl;
                        //cout << "change: " << change[1] << " " << change[2] << " " << change[3] << " " << change[4] << endl;
                        //cout << "d: " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << endl;
               
                        if (c1 == c2)
                        {
                                cout << "YES" << endl;
                                sh = (sh + 1) % n;
                        }
                        else
                                cout << "NO" << endl;
                        //cout << endl;
                }
        }
       
        return 0;
}