#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;
long long N, M;
long long cd;
long long result;
int it;
set<long long> vec;
int main()
{
  scanf("%lld %lld", &N, &M);
  while(N != 0 || M != 0)
  {
    result = 0;
    vec.clear();
    while(N--)
    {
      scanf("%lld", &cd);
      vec.insert(cd);
    }
    while(M--)
    {
      scanf("%lld", &cd);
      it = vec.count(cd);
      result = (it != 1) ? result : ++result;
    }
    printf("%lld\n", result);
    scanf("%lld %lld", &N, &M);
  }
}
