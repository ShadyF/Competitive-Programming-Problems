#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, dfs_num_counter;
string line;
vector<vector<int> > adj_list;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> dfs_parent;
vector<bool> articulation_vertex;
int dfs_root, root_children;

void ArticulationPoint(int u)
{
    dfs_num[u] = dfs_low[u] = dfs_num_counter++;
    for(int i = 0; i < adj_list[u].size(); i++)
    {
        int v = adj_list[u][i];
        if(dfs_num[v] == -1)
        {
            dfs_parent[v] = u;
            if(u == dfs_root) root_children++;

            ArticulationPoint(v);

            if(dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = true;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N && N != 0)
    {
        adj_list.clear();
        adj_list.resize((unsigned long) N);
        cin.ignore();
        while (true)
        {
            getline(cin, line);
            if (line[0] == '0')
                break;
            stringstream s(line);
            int u, v;
            s >> u;
            while (s.good())
            {
                s >> v;
                adj_list[v-1].push_back(u-1);
                adj_list[u-1].push_back(v-1);
            }
        }
        dfs_num_counter = 0;
        dfs_num.clear(); dfs_num.resize(N, -1);
        dfs_low.clear(); dfs_low.resize(N, 0);
        dfs_parent.clear(); dfs_parent.resize(N, 0);
        articulation_vertex.clear(); articulation_vertex.resize(N, false);

        for(int i = 0; i < N; i++)
            if (dfs_num[i] == -1)
            {
                dfs_root = i; root_children = 0;
                ArticulationPoint(i);
                articulation_vertex[dfs_root] = (root_children > 1);
            }
        cout << count_if(articulation_vertex.begin(), articulation_vertex.end(), [] (bool i) {return i;}) << endl;
    }
}
