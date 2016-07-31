#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <sstream>

using namespace std;
int E, M, T;
vector<int> dist;
vector<vector<int> > AdjList;
queue<int> q;
map<int, int> boom_days;

void BFS(int u)
{
    dist.clear();
    dist.resize(E, -1);
    boom_days.clear();
    dist[u] = 0;
    boom_days[0] = 1;
    while (!q.empty())
        q.pop();
    q.push(u);
    while (!q.empty())
    {
        int vertex_u = q.front();
        q.pop();
        for (int i = 0; i < AdjList[vertex_u].size(); i++)
        {
            int v = AdjList[vertex_u][i];
            if (dist[v] == -1)
            {
                dist[v] = dist[vertex_u] + 1;
                if (boom_days[dist[v]])
                    boom_days[dist[v]]++;
                else
                    boom_days[dist[v]] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> E;
    AdjList.resize(E);
    for (int i = 0; i < E; i++)
    {
        cin >> M;
        int temp;
        for (int j = 0; j < M; j++)
        {
            cin >> temp;
            AdjList[i].push_back(temp);
        }
    }
    cin >> T;
    while (T--)
    {
        int u;
        cin >> u;
        BFS(u);
        if (boom_days.size() == 1)
            cout << 0 << endl;
        else
        {
            auto x = max_element(boom_days.begin(), boom_days.end(), [](pair<int, int> p1, pair<int, int> p2)
            {
                return p1.second < p2.second;
            });
            if(x->first != 0)
                cout << x->second << " " << x->first << endl;
            else
                cout << x->second << " " << 1 << endl;
        }
    }
}
