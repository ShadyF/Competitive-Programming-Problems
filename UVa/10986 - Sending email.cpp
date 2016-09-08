#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, n, m, S, T;
int case_num = 0;
vector<int> dist;
vector<vector<pair<int, int>>> AdjList;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> n >> m >> S >> T;
        AdjList.clear();
        AdjList.resize(n);
        dist.clear();
        dist.resize(n, -1);

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            AdjList[u].push_back(make_pair(v, w));
            AdjList[v].push_back(make_pair(u, w));
        }

        pq.push(make_pair(0, S));
        dist[S] = 0;
        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;
            for (int i = 0; i < AdjList[u].size(); i++)
            {
                auto v = AdjList[u][i];
                if (dist[u] + v.second < dist[v.first] || dist[v.first] == -1)
                {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(make_pair(dist[v.first], v.first));
                }
            }
        }
        cout << "Case #" << ++case_num << ": ";
        dist[T] == -1 ? cout << "unreachable" : cout << dist[T];
        cout << endl;
    }
}
