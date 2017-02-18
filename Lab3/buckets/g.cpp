#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int ST = 16;
const int MAX = (1 << ST), MAXN = 1e5 + 5;
unsigned int cur = 0, a, b;  
unsigned int aa[MAXN], cc[MAX], bb[MAXN]; 

unsigned int nextRand24() {
  cur = cur * a + b;
  return cur >> 8;
}

unsigned int nextRand32() {
  unsigned int a = nextRand24(), b = nextRand24();
  return (a << 8) ^ b;
}

int main() {
  freopen("buckets.in", "r", stdin);
  freopen("buckets.out", "w", stdout);
  int t, n;
  cin >> t >> n >> a >> b;

  for (int i = 0; i < t; i++) {  
    for (int j = 0; j < n; j++) {
      aa[j] = nextRand32();
      //cout << aa[j] << "\n";
    }

    memset(cc, 0, MAX * sizeof(unsigned int));
    
    for (int j = 0; j < n; j++) {
      unsigned int el = aa[j] & ((1 << ST) - 1);
      cc[el]++;
    }
    
    for (int j = 1; j < MAX; j++)
      cc[j] += cc[j - 1]; 
    
    for (int j = n - 1; j >= 0; j--) {
      unsigned int el = aa[j] & ((1 << ST) - 1);
      cc[el]--;
      bb[cc[el]] = aa[j];
    }
    
    memset(cc, 0, MAX * sizeof(unsigned int));   

    for (int j = 0; j < n; j++) {
      unsigned int el = bb[j] >> ST;
      cc[el]++;
    }
    
    for (int j = 1; j < MAX; j++)
      cc[j] = cc[j - 1] + cc[j]; 
    
    for (int j = n - 1; j >= 0; j--) {
      unsigned int el = bb[j] >> ST;
      //cerr << el << " ";
      cc[el]--;
      //cerr << cc[el] << "\n";
      aa[cc[el]] = bb[j];
    }
    
    unsigned long long res = 0;

    for (int j = 0; j < n; j++) {
      res += 1ull* (j + 1) * aa[j];
      //cerr << aa[j] << "\n";
    } 

    cout << res << endl;
  }                      

  return 0;
}
