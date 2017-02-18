#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
using namespace std;
 
struct node
{
    long long val;
    node *next;
};
 
int main()
{
  //ios::sync_with_stdio(false);
  freopen("postfix.in", "r", stdin);
  freopen("postfix.out", "w", stdout);
 
  char s[105];
  node *first = new node[1];
 
  while(scanf("%s", s) > 0)
  {  
    if (s[0] >= '0' && s[0] <= '9')
    {
      node *second = new node[1];
      second->val = s[0] - '0';
      second->next = first;
      first = second;
    }
    else
    {
      long long a = first->val;
      first = first->next;
      long long b = first->val;
      first = first->next;
      long long c = 0;
      if (s[0] == '*')
        c = a * b;
      else if (s[0] == '+')
        c = a + b;
      else
        c = b - a;  
 
      node *second = new node[1];
      second->val = c;
      second->next = first;
      first = second;
    }
  }
 
  cout << first->val << endl;
 
  return 0;
}