#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int n, dfs_num_counter;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> dfs_parent;
vector<pair<int, int>> articulation_edges;
string line;
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
            ArticulationPoint(v);

            if (dfs_low[v] > dfs_num[u])
                articulation_edges.push_back(make_pair(min(u, v), max(u, v)));
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);       //update dfs_low[u]
        }
        else if (v != dfs_parent[u])        // a backedge, not a direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main()
{
    while (cin >> n)
    {
        dfs_num_counter = 0;
        adj_list.clear(); adj_list.resize(n);
        dfs_num.clear(); dfs_num.resize(n, -1);
        dfs_low.clear(); dfs_low.resize(n, 0);
        dfs_parent.clear(); dfs_parent.resize(n, 0);
        articulation_edges.clear();
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            getline(cin, line);
            stringstream s(line);
            int index, temp;
            s >> index;
            s >> line;
            while (s.good())
            {
                s >> temp;
                adj_list[index].push_back(temp);
            }
        }
        dfs_num_counter = 0;
        for(int i = 0; i < n; i++)
            if (dfs_num[i] == -1)       //not visited
                ArticulationPoint(i);
        if(!articulation_edges.empty())
        {
            sort(articulation_edges.begin(), articulation_edges.end(),
                 [](pair<int, int> i, pair<int, int> j)  { return i.first == j.first ? i.second < j.second : i.first < j.first; }
            );
            cout << articulation_edges.size() << " critical links\n";
        }
        else
            cout << "0 critical links\n";
        for(int i = 0; i < articulation_edges.size(); i++)
        {
            cout << articulation_edges[i].first << " - " << articulation_edges[i].second << endl;
        }
        cout << endl;
    }
}