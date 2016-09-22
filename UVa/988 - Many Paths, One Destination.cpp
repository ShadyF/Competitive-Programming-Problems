#include <bits/stdc++.h>

using namespace std;

int V, n;
vector<vector<int>> AdjList;
vector<bool> visited;
stack<int> TopSort;
vector<int> endings;
vector<int> num_paths;
void topologicalSort(int u)
{
    visited[u] = true;
    for (int i = 0; i < AdjList[u].size(); i++)
        if (!visited[AdjList[u][i]])
            topologicalSort(AdjList[u][i]);

    // Only difference between this and DFS is this single line
    // The last vertex in the DFS sequence i.e the deepest one is added.
    TopSort.push(u);

}

int main() {
    bool flag = true;
    while (cin >> V) {
        if(flag) flag = false;
        else cout << endl;
        AdjList.clear();
        AdjList.resize(V+2);
        num_paths.clear();
        num_paths.resize(V+2);
        visited.clear();
        visited.resize(V+2);
        endings.clear();
        for (int i = 0; i < V; i++) {
            cin >> n;
            if(n == 0) endings.push_back(i);
            for(int j = 0; j < n; j++)
            {
                int v;
                cin >> v;
                AdjList[i].push_back(v);
            }
        }
        topologicalSort(0);
        num_paths[0] = 1;
        while(!TopSort.empty())
        {
            auto front = TopSort.top();
            TopSort.pop();
            for(int i = 0; i < AdjList[front].size(); i++)
            {
                int v = AdjList[front][i];
                num_paths[v] += num_paths[front];
            }
        }

        int result = 0;
        for(auto x : endings)
            result += num_paths[x];
        if(result == 0) result = 1;
        cout << result << endl;
    }
}
