// IMPORTANT
// Gives WA even though I can't find a test case that makes it fail til now

#include <bits/stdc++.h>

using namespace std;
int n;
vector<vector<pair<int, int>>> AdjList;
vector<int> dist;

const int INF = -0x3f3f3f3f;

int main()
{
    while (cin >> n && n != -1)
    {
        dist.clear();
        dist.resize(n+5, INF);
        AdjList.clear();
        AdjList.resize(n+5);
        for (int i = 0; i < n; i++)
        {
            int energy, doors, v;
            cin >> energy >> doors;
            for (int j = 0; j < doors; j++)
            {
                cin >> v;
                AdjList[i].push_back({--v, energy});
            }
        }

        dist[0] = 100;
        bool modified = true;
        for (int i = 0; i < n - 1 && modified; i++)
        {
            modified = false;
            for (int u = 0; u < n; u++)
                for (int j = 0; j < AdjList[u].size(); j++)
                {
                    auto v = AdjList[u][j];
                    if (dist[u] + v.second > dist[v.first] && dist[u] > 0)
                    {
                        dist[v.first] = dist[u] + v.second;
                        modified = true;
                    }
                }
        }
        bool hasPosCycle = false;
        for (int u = 0; u < n; u++)
            for (int j = 0; j < AdjList[u].size(); j++)
            {
                auto v = AdjList[u][j];
                if (dist[u] + v.second > dist[v.first] && dist[u] > 0)
                    hasPosCycle = true;
            }
        if (dist[n-1] == INF)
            cout << "hopeless\n";
        else if (dist[n-1] > 0 || hasPosCycle)
            cout << "winnable\n";
        else
            cout << "hopeless\n";
    }

}
