#include <cstdio>
#include <bitset>
#include <cstring>
using namespace std;

int e, v, tree, acorn, N;
char s[100];
bitset<26> A;
int main()
{
  scanf("%d\n", &N);
  while(N--)
  {
  A.reset();
  e = 0, tree = 0, acorn = 0;
  memset(s, '\0', sizeof(s));
  while( gets(s) && *s != '*')
  {
    A[s[1] - 65] = 1;
    A[s[3] - 65] = 1;
    ++e;
  }
  gets(s);
  v = strlen(s) - strlen(s)/2;
  acorn = v - A.count();
  tree = v - e - acorn;
  printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
  scanf("%d\n", &N);
  }
}