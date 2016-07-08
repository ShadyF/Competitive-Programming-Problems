#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int T, n, m;
vector<bool> visited;
vector<vector<int> > adj_list;
vector<int> sorted_array;

void TopSort(int u)
{
    visited[u] = true;
    for (int i = 0; i < adj_list[u].size(); i++)
    {
        int v = adj_list[u][i];
        if (!visited[v])
            TopSort(v);
    }
    sorted_array.push_back(u);
}

void DFS(int u)
{
    visited[u] = true;
    for (int i = 0; i < adj_list[u].size(); i++)
    {
        int v = adj_list[u][i];
        if (!visited[v])
            DFS(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        adj_list.clear();
        adj_list.resize(n);
        visited.clear();
        visited.resize(n, false);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj_list[u - 1].push_back(v - 1);
        }
        for (int i = 0; i < n; i++)
            if (!visited[i])
                TopSort(i);
        reverse(sorted_array.begin(), sorted_array.end());
        fill(visited.begin(), visited.end(), false);
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            int u = sorted_array[i];
            if (!visited[u])
            {
                num++;
                DFS(u);
            }
        }
        cout << num << endl;
    }
}
