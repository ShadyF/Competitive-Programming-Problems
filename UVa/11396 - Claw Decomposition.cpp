#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nodes, edges;
vector< vector<int> > adj_list;
vector<int> color;
queue<int> q;
bool isBipartite;

void BFS(int u)
{
  q.push(u);
  color[u] = 0;
  while(!q.empty() && isBipartite)
  {
    int u = q.front(); q.pop();
    for(int i = 0; i < adj_list[u].size(); i++)
    {
      int v = adj_list[u][i];
      if(color[v] == -1)
      {
        color[v] = 1 - color[u];
        q.push(v);
      }
      else if(color[u] == color[v])
      {
        isBipartite = false;
        return;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while(cin >> nodes && nodes != 0)
  {
    adj_list.clear();
    adj_list.resize(nodes);
    color.clear();
    color.resize(nodes, -1);
    while(!q.empty())
      q.pop();
    int u = -1, v = -1;
    while (cin >> u >> v && (u != 0 || v != 0))
    {
      adj_list[u-1].push_back(v-1);
      adj_list[v-1].push_back(u-1);
    }

    isBipartite = true;
    for(int i = 0; i < nodes && isBipartite; i++)
      if(color[i] == -1)
        BFS(i);

    if(isBipartite)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
