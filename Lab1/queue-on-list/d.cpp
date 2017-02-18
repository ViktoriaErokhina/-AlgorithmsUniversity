#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
 
struct node
{
    int val;
    node *next;
};
 
int main()
{
  //ios::sync_with_stdio(false);
  freopen("queue2.in", "r", stdin);
  freopen("queue2.out", "w", stdout);
 
  int n;
  scanf("%d", &n);

  node *first = new node[1];
  node *last = new node[1];
  last = first;

  for (int i = 0; i < n; i++)
  { 
    char c;
    scanf("%c", &c);
    scanf("%c", &c);
 
    if (c == '-')
    {
      printf("%d\n", (first->next)->val);
      first = first->next;
    }
    else if (c == '+')
    {
      int x;
      scanf("%d", &x);
 
      node *second = new node[1];
      second->val = x;
      last->next = second;
      last = second;
    }
  }
 
  return 0;
}