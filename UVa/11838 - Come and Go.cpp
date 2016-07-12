#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N, M, dfs_num_counter, numSCC;
vector<bool> visited;
vector<int> dfs_num;
vector<int> dfs_low;
vector< vector<int> > adj_list;
stack<int> result;
void tarjanSCC(int u)
{
    if(numSCC > 1)
        return;

    dfs_num[u] = dfs_low[u] = dfs_num_counter++;
    result.push(u);
    visited[u] = true;
    for (int i = 0; i < adj_list[u].size(); i++)
    {
        int v = adj_list[u][i];
        if (dfs_num[v] == -1)
            tarjanSCC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u])
    {
        numSCC++;
        while(true)
        {
            int v = result.top();
            result.pop();
            visited[v] = false;
            if(u == v) break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N >> M && (N != 0 || M != 0))
    {
        adj_list.clear(); adj_list.resize(N);
        visited.clear(); visited.resize(N, false);
        dfs_low.clear(); dfs_low.resize(N);
        dfs_num.clear(); dfs_num.resize(N, -1);
        while(!result.empty())
            result.pop();
        while(M--)
        {
            int V, W, P;
            cin >> V >> W >> P;
            V--; W--;
            adj_list[V].push_back(W);
            if(P == 2)
                adj_list[W].push_back(V);
        }
        numSCC = 0; dfs_num_counter = 0;
        for(int i = 0; i < N && numSCC < 2; i++)
            if(dfs_num[i] == -1)
                tarjanSCC(i);
        if(numSCC == 1)
            cout << "1\n";
        else
            cout << "0\n";
    }
}
