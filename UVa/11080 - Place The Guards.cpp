#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, nodes, edges, ans;
vector< vector<int> > adj_list;
vector<int> color;
queue<int> q;
bool isBipartite;
int BFS(int u)
{
  q.push(u);
  color[u] = 0;
  int tot = 0, m = 0;
  while(!q.empty())
  {
    int u = q.front(); q.pop();
    tot++;
    m = color[u] == 0 ? m + 1 : m;
    for(int i = 0; i < adj_list[u].size(); i++)
    {
      int v = adj_list[u][i];
      if(color[v] == -1)
      {
        color[v] = 1 - color[u];
        q.push(v);
      }
      else if(color[u] == color[v])
        return -1;
    }
  }
  if(tot == 1) return 1;
  return min(m, tot-m);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while(T--)
  {
    cin >> nodes >> edges;
    adj_list.clear();
    adj_list.resize(nodes);
    color.clear();
    color.resize(nodes, -1);

    while(!q.empty())
      q.pop();

    for(int i = 0; i < edges; i++)
    {
      int u, v;
      cin >> u >> v;
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }
    ans = 0;
    isBipartite = true;
    for(int k = 0; k < nodes; k++)
    {
      if(color[k] == -1)
      {
        int temp = BFS(k);
        if(temp == -1)
        {
          isBipartite = false;
          break;
        }
        ans += temp;
      }
    }
    if(isBipartite)
      cout << ans << endl;
    else
      cout << "-1\n";
  }
}
