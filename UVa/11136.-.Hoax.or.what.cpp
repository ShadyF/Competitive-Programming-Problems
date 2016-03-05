#include <cstdio>
#include <set>

using namespace std;

long N;
long num;
long inc;
long temp;
long res;
long b, a;
multiset<long> m;
int main()
{
  scanf("%ld", &N);
  while(N != 0)
  {
    res = 0;
    inc = N;
    m.clear();
    while(inc--)
    {
      scanf("%ld", &num);
      for(int i = 0; i < num; i++)
      {
        scanf("%ld", &temp);
        m.insert(temp);
      }
      b = *m.rbegin();
      a = *m.begin();
      res += b - a;
      m.erase(m.find(b));
      m.erase(m.find(a));
    }
    printf("%ld\n", res);
    scanf("%ld", &N);
  }
}
