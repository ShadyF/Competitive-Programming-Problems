#include <bits/stdc++.h>

using namespace std;

int N, R, C;
int grid[110][110];
vector<vector<vector<pair<int, int>>>> AdjList;
string case_name;
bool visited[110][110];
int dist[110][110];
const int NEG_INF = -1;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};
stack<pair<int, int>> TopSort;

void topologicalSort(int u1, int u2) {
    visited[u1][u2] = true;
    for (int i = 0; i < AdjList[u1][u2].size(); i++)
        if (!visited[AdjList[u1][u2][i].first][AdjList[u1][u2][i].second])
            topologicalSort(AdjList[u1][u2][i].first, AdjList[u1][u2][i].second);

    // Only difference between this and DFS is this single line
    // The last vertex in the DFS sequence i.e the deepest one is added.
    TopSort.push({u1, u2});

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    while (N--) {
        cin >> case_name >> R >> C;
        memset(grid, -1, sizeof(grid));
        memset(visited, false, sizeof(visited));
        memset(dist, NEG_INF, sizeof(dist));
        AdjList.clear();
        AdjList.resize(R);
        for (int i = 0; i < R; i++) {
            AdjList[i].resize(C);
            for (int j = 0; j < C; j++)
                cin >> grid[i][j];
        }
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                int u = grid[i][j];
                for (int k = 0; k < 4; k++)
                    if (i + dr[k] >= 0 && j + dc[k] >= 0 && i + dr[k] < R && j + dc[k] < C &&
                        grid[i + dr[k]][j + dc[k]] < u)
                        AdjList[i][j].push_back({i + dr[k], j + dc[k]});
            }

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (!visited[i][j])
                    topologicalSort(i, j);

        dist[TopSort.top().first][TopSort.top().second] = 1;
        while (!TopSort.empty()) {
            auto front = TopSort.top();
            TopSort.pop();
            if (!TopSort.empty() && dist[TopSort.top().first][TopSort.top().second] == NEG_INF)
                dist[TopSort.top().first][TopSort.top().second] = 1;
            if (dist[front.first][front.second] != NEG_INF)
                for (int i = 0; i < AdjList[front.first][front.second].size(); i++) {
                    auto v = AdjList[front.first][front.second][i];
                    dist[v.first][v.second] = max(dist[v.first][v.second], dist[front.first][front.second] + 1);
                }
        }

        int max_val = NEG_INF;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                max_val = max(dist[i][j], max_val);
        cout << case_name <<": " << max_val << endl;
    }
}
