#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int l, u, v;
vector<vector<int> > adj_list;
vector<int> colors;
queue<int> q;
bool isBipartite;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while(cin >> n && n != 0)
  {
    cin >> l;
    adj_list.clear();
    colors.clear();
    while(!q.empty())
      q.pop();
    adj_list.resize(n);
    colors.resize(n, -1);

    for(int i = 0; i < l; i++)
    {
      cin >> u >> v;
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }
    q.push(0);
    colors[0] = 0;
    isBipartite = true;
    while(!q.empty() && isBipartite)
    {
      int x = q.front(); q.pop();
      for(int i = 0; i < adj_list[x].size(); i++)
      {
        if(colors[adj_list[x][i]] == -1)
        {
          colors[adj_list[x][i]] = 1 - colors[x];
          q.push(adj_list[x][i]);
        }
        else if(colors[x] == colors[adj_list[x][i]])
        {
          isBipartite = false;
          break;
        }

      }
    }
    if(isBipartite)
      cout << "BICOLORABLE.\n";
    else
      cout << "NOT BICOLORABLE.\n";
  }
}
