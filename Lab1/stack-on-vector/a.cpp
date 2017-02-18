#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
 
int main()
{
  freopen("stack1.in", "r", stdin);
  freopen("stack1.out", "w", stdout);
 
  int n;
  scanf("%d", &n);
 
  //int *st = (int *)malloc(sizeof(int));
  int *st = new int[1];
  int size = 0;
  int len = 1;
 
  for (int i = 0; i < n; i++)
  {
    char c;
    scanf("%c", &c);
    scanf("%c", &c);
 
    if (c == '-')
    {
      if (size <= len / 4)
      {
        len /= 2;
        //int *st2 = (int *)malloc(sizeof(int) * len);
        int *st2 = new int[len];
        for (int j = 0; j < size; j++)
          st2[j] = st[j];
        delete(st);
        st = st2;
        //free(st2);
      }
      
      printf("%d\n", st[size - 1]);
      //cout.flush();
      size--;
    }
    else if (c == '+')
    { 
      if (size + 1 > len)
      {
        len *= 2;
        //int *st2 = (int *)malloc(sizeof(int) * len);
        int *st2 = new int[len];
        for (int j = 0; j < size; j++)
          st2[j] = st[j];
        delete(st);
        st = st2;
        //free(st2);
      }
 
      int x;
      scanf("%d", &x);
      st[size] = x;
      size++;
    }
  }
 
  return 0;
}