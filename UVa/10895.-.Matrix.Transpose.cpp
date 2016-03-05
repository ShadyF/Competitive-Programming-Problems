#include <cstdio>
#include <vector>

using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii; // data type shortcuts
int m, n, r;
int row, num, col;
int main()
{
  while(scanf("%d %d", &m, &n) != EOF)
  {
    vector<vii> AdjList;
    vector<int> rows;
    AdjList.resize(m+5);
    row = 0;
    for(int i = 0; i<m; i++, row++)
    {
      rows.clear();
      scanf("%d", &r);
      if(r == 0)
        continue;
      for(int i = 0; i<r; i++)
      {
        scanf("%d", &num);
        rows.push_back(num);
      }
      for(int i = 0; i < r; i++)
      {
        scanf("%d", &num);
        AdjList[rows[i] - 1].push_back(make_pair(num, row + 1));
      }
    }
    printf("%d %d\n", n, m);
    for(int i = 0; i < n; i++)
    {
      printf("%d", AdjList[i].size());
      for(auto x : AdjList[i])
        printf(" %d", x.second);
      printf("\n");
      for(int j = 0; j< AdjList[i].size(); j++)
      {
        if(j == AdjList[i].size() - 1)
          printf("%d", AdjList[i][j].first);
        else
          printf("%d ", AdjList[i][j].first);  //what the fuck??
      }
      printf("\n");
    }
  }
}