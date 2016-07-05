#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int dfs_num_counter;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> dfs_parent;
vector<int> articulation_vertex;
vector<pair<int, int>> result;
int dfs_root, root_children;
vector<vector<int> > adj_list;

void ArticulationPoint(int u)
{
    dfs_num[u] = dfs_low[u] = dfs_num_counter++;
    for (int i = 0; i < adj_list[u].size(); i++)
    {
        int v = adj_list[u][i];
        if (dfs_num[v] == -1)
        {
            dfs_parent[v] = u;
            if (u == dfs_root) root_children++;

            ArticulationPoint(v);

            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u]++;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m && ( n != 0 || m != 0 ))
    {
        adj_list.clear();
        adj_list.resize(n);
        result.clear();
        result.resize(n);
        int u, v;
        while (cin >> u >> v && u != -1 && v != -1)
        {
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        dfs_num_counter = 0;
        dfs_num.clear(); dfs_num.resize(n, -1);
        dfs_low.clear(); dfs_low.resize(n, 0);
        dfs_parent.clear(); dfs_parent.resize(n, 0);
        articulation_vertex.clear(); articulation_vertex.resize(n, 1);

        for (int i = 0; i < n; i++)
            if (dfs_num[i] == -1)
            {
                dfs_root = i;
                root_children = 0;
                ArticulationPoint(i);
                articulation_vertex[dfs_root] = root_children;
            }
        for (int i = 0; i < n; i++)
        {
            result.push_back(make_pair(i, articulation_vertex[i]));
        }
        sort(result.begin(), result.end(), [](pair<int, int> i, pair<int, int> j)
        {
            return i.second == j.second ? i.first < j.first : i.second > j.second;
        });
        for(int i = 0; i < m; i++)
            cout << result[i].first << " " <<result[i].second <<endl;
        cout << endl;
    }
}