#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
  
struct node
{
    char val;
    node *next;
};
  
char c[100][100];
  
int main()
{
  ios::sync_with_stdio(false);
  freopen("brackets.in", "r", stdin);
  freopen("brackets.out", "w", stdout);
  
  int n;
  scanf("%d", &n);  
  
  char s[1000000];
  
  while(scanf("%s", s) > 0)
  {
    int i = 0;
    int cnt = 0;
    node *first = new node[1];
    //int b = scanf("%c", &c);
    //if (b <= 0)
      //return 0;
    //int fl = 0;
    while (s[i] != 0)
    {
      if (cnt > 0 && ((first->val == '[' && s[i] == ']') || (first->val == '(' && s[i] == ')')))
      {
        first = first->next;
        cnt--;
      }
      else
      { 
        node *second = new node[1];
        second->val = s[i];
        second->next = first;
        first = second;
        cnt++;
      }
      i++;
    }
    if (cnt == 0)
      printf("YES\n");
    else
      printf("NO\n"); 
  }
  
  
  
  return 0;
}