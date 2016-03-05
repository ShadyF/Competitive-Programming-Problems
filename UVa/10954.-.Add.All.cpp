#include <cstdio>
#include <queue>
#include <functional>

using namespace std;
long long N;
long long x;
long long temp, a, b;
long long cost;
int main()
{
  while(scanf("%lld", &N) && N != 0)
  {
    cost = 0;
    priority_queue<long long, vector<long long>, greater<long long> > q;
    while(N--)
    {
      scanf("%lld", &x);
      q.push(x);
    }
    while(q.size() > 1)
    {
      a = q.top();
      q.pop();
      b = q.top();
      q.pop();
      temp = a + b;
      cost+= temp;
      q.push(temp);
    }
    printf("%lld\n", cost);
  }
}
