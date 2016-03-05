#include <limits.h>
#include <cstdio>

using namespace std;

int n, a, b;
bool flag;

int main()
{
  while(scanf("%d", &n) == 1)
  {
    if(n == 0)
      return 0;
    a = 0, b = 0, flag = true;
    for(int i = 1, k = 1; k <= n && i < 32; k = 1 << i++)
    {
      if (k & n && flag)
      {
        flag ^= 1;
        a |= k;
      }
      else if (k & n && !flag)
      {
        flag ^= 1;
        b |= k;
      }
    }

    printf("%d %d\n", a, b);
  }
}