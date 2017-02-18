#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
 
int main()
{
  //ios::sync_with_stdio(false);
  freopen("queue1.in", "r", stdin);
  freopen("queue1.out", "w", stdout);
 
  int n;
  scanf("%d", &n);
 
  int *st = new int[1];
  int first = 0;
  int len = 1;
  int last = 0;
 
  for (int i = 0; i < n; i++)
  {  
    char c;
    scanf("%c", &c);
    scanf("%c", &c);
 
    if (c == '-')
    {
       
      if (first > len / 2)
      {
        len /= 2;
        //int *st2 = (int *)malloc(sizeof(int) * len);
        int *st2 = new int[len];
        for (int j = 0; j < last - first; j++)
          st2[j] = st[first + j];
        last -= first;
        first = 0;
        delete(st);
        st = st2;
      }
       
      printf("%d\n", st[first]);
      first++;
    }
    else if (c == '+')
    {
      if (last > len - 1)
      {
        len *= 2;
        int *st2 = new int[len];
        for (int j = 0; j < last - first; j++)
          st2[j] = st[first + j];
        last -= first;
        first = 0;
        delete(st);
        st = st2;
      }
 
      int x;
      scanf("%d", &x);
      st[last] = x;
      last++;
    }
  }
 
  return 0;
}