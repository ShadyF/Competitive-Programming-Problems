#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int in;
int Max;
int temp;
map<set<int>, int> m;
set<int> s;
int main()
{
  scanf("%d", &N);
  while(N != 0)
  {
    temp = N;
    m.clear();
    while(N--)
    {
      s.clear();
      for(int i = 0; i<5; i++)
      {
        scanf("%d", &in);
        s.insert(in);
      }
      m[s]++;
    }
    Max = 0;
    temp = 0;
    for(auto x : m)
      Max = max(Max, x.second);
    for(auto x : m)
      temp = (x.second == Max) ? temp+x.second : temp;
    printf("%d\n", temp);

    scanf("%d", &N);
  }
}