#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;
long long x;
set<long long> s;
int N;
int num;
int res;
int main()
{
  scanf("%d", &N);
  while(N--)
  {
    res = 0;
    s.clear();
    scanf("%d", &num);
    while(num--)
    {
      scanf("%d", &x);
      auto search = s.find(x);
      if(search == s.end())
      {
        res++;
        s.insert(x);
      }
    }
    printf("OUT: %d\n", res);
  }
}