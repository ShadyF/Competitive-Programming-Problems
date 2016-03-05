//can be done using map<int, vector<int>> ?
#include <vector>
#include <map>
#include <cstdio>

using namespace std;
int n, m, k, v;
int main()
{
  while(scanf("%d %d", &n, &m) != EOF)
  {
    map<int, vector<int>> list;
    for(int i = 1; i<=n; i++)
    {
      scanf("%d", &v);
      list[v].push_back(i);
    }
    while(m--)
    {
      scanf("%d %d", &k, &v);
      if(k > list[v].size())
        printf("0\n");
      else
        printf("%d\n", list[v][k - 1]);
    }
  }
}