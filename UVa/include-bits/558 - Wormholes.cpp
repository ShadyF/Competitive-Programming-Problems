#include <bits/stdc++.h>

using namespace std;

int c, n, m;
vector<int> dist;
vector<vector<pair<int, int>>> AdjList;

int main()
{
    cin >> c;
    while (c--)
    {
        cin >> n >> m;
        dist.clear();
        dist.resize(n, 0x3f3f3f3f);
        AdjList.clear();
        AdjList.resize(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            AdjList[u].push_back({v, w});
        }
        dist[0] = 0;

        bool modified = true;
        for (int i = 0; i < n - 1 && modified; i++)
        {
            modified = false;
            for (int u = 0; u < n; u++)
                for (int j = 0; j < AdjList[u].size(); j++)
                {
                    auto v = AdjList[u][j];
                    if (dist[u] + v.second < dist[v.first])
                    {
                        dist[v.first] = dist[u] + v.second;
                        modified = true;
                    }
                }
        }

        bool hasNegativeCycle = false;
        for (int u = 0; u < n; u++)
            for (int j = 0; j < AdjList[u].size(); j++)
            {
                auto v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first])
                    hasNegativeCycle = true;
            }

        if (hasNegativeCycle)
            cout << "possible\n";
        else
            cout << "not possible\n";
    }
}
