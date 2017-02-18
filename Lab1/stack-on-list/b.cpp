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
  freopen("stack2.in", "r", stdin);
  freopen("stack2.out", "w", stdout);
 
  int n;
  scanf("%d", &n);
 
  node *first = new node[1];

  for (int i = 0; i < n; i++)
  {  
    char c;
    scanf("%c", &c);
    scanf("%c", &c);
 
    if (c == '-')
    {
      printf("%d\n", first->val);
      first = first->next;
    }
    else if (c == '+')
    {
      int x;
      scanf("%d", &x);
 
      node *second = new node[1];
      second->val = x;
      second->next = first;
      first = second;
    }
  }
 
 
  return 0;
}