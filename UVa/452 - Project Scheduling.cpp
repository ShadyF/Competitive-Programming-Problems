#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
stack<int> TopSort;
vector<vector<pair<int, int>>> AdjList;
vector<int> dist;

const int INF = -0x3f3f3f3f;

void topologicalSort(int u) {
    visited[u] = true;
    for (int i = 0; i < AdjList[u].size(); i++)
        if (!visited[AdjList[u][i].first])
            topologicalSort(AdjList[u][i].first);

    // Only difference between this and DFS is this single line
    // The last vertex in the DFS sequence i.e the deepest one is added.
    TopSort.push(u);
}

int main() {
    string temp_string;
    int T;
    getline(cin, temp_string);
    stringstream what(temp_string);
    what >> T;
    getline(cin, temp_string);
    bool flag = false;

    while (T--) {
        if (flag) cout << endl;
        else
            flag = true;

        getline(cin, temp_string);
        dist.clear();
        dist.resize(500, INF);
        AdjList.clear();
        AdjList.resize(500);
        visited.clear();
        visited.resize(500, false);

        while (!temp_string.empty()) {
            char u_char, v_char, temp_char;
            int u, v, w;
            stringstream s(temp_string);
            s >> u_char >> w;
            u = u_char - 64;
            s >> v_char;
            if (v_char == '\000' || !s.good())
                AdjList[0].push_back({u, w});
            while (s.good()) {
                if (v_char == '\000')
                    break;
                v = v_char - 64;
                AdjList[v].push_back({u, w});
                s >> v_char;
            }
            getline(cin, temp_string);
        }

        for (int i = 0; i < 500; i++)
            if (!visited[i])
                topologicalSort(i);
        dist[0] = 0;

        while (TopSort.top() != 0)
            TopSort.pop();

        while (!TopSort.empty()) {
            int u = TopSort.top();
            TopSort.pop();
            if (dist[u] != INF) {
                for (int i = 0; i < AdjList[u].size(); i++) {
                    auto v = AdjList[u][i];
                    dist[v.first] = max(dist[v.first], dist[u] + v.second);
                }
            }
        }

        int max_val = INF;
        for (int i = 0; i < 500; i++)
            if (dist[i] > INF)
                max_val = max(dist[i], max_val);

        cout << max_val << endl;
    }
}
