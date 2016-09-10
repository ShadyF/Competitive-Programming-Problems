#include <bits/stdc++.h>

using namespace std;

int n, temp, r, q;
int case_num = 0;
vector<int> dist;
vector<int> busyness_vector;
vector<vector<pair<int, int>>> AdjList;
const int INF = 0x3f3f3f3f;

int main()
{
    while (cin >> n)
    {
        dist.clear();
        dist.resize(n + 1, INF);
        AdjList.clear();
        AdjList.resize(n + 1);
        busyness_vector.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            busyness_vector.push_back(--temp);
        }
        cin >> r;
        for (int i = 0; i < r; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            AdjList[u].push_back({v, pow(busyness_vector[v] - busyness_vector[u], 3)});
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
        for (int i = 0; i < n - 1; i++)
        {
            for (int u = 0; u < n; u++)
                for (int j = 0; j < AdjList[u].size(); j++)
                {
                    auto v = AdjList[u][j];
                    if (dist[u] + v.second < dist[v.first])
                    {
                        dist[v.first] = -INF;
                    }
                }
        }
        cin >> q;
        cout << "Set #" << ++case_num << endl;
        while (q--)
        {
            int v;
            cin >> v;
            v--;
            if (dist[v] < 3 || dist[v] >= 1000000000)
                cout << "?\n";
            else
                cout << dist[v] << endl;
        }
    }

}
