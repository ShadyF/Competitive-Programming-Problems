#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N;
int num;
vector<vector<int>> AdjList;
vector<bool> visited;
vector<int> heights;
int furthest;
int max_height;
vector<int> best;
set<int> worst;
vector<int> parent;

void dfs(int u, int height) {
    visited[u] = true;
    heights[u] = height;
    if (max_height <= height) {
        max_height = height;
        furthest = u;
    }
    for (int j = 0; j < (int) AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (visited[v] == false) {
            parent[v] = u;
            dfs(v, height + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N) {
        AdjList.clear();
        AdjList.resize(N + 2);
        visited.clear();
        visited.resize(N + 2, false);
        heights.clear();
        heights.resize(N + 2);
        best.clear();
        worst.clear();
        parent.clear();
        parent.resize(N+2);
        for (int i = 0; i < N; i++) {
            cin >> num;
            while (num--) {
                int v;
                cin >> v;
                AdjList[i].push_back(--v);
                AdjList[v].push_back(i);
            }
        }
        max_height = 0;
        dfs(0, 0);
        fill(visited.begin(), visited.end(), false);
        parent.clear();
        max_height = 0;
        dfs(furthest, 0);
        if (max_height % 2 == 0)
            for (int i = furthest; ; i = parent[i]) {
                if (heights[i] == max_height / 2) {
                    best.push_back(i);
                    break;
                }
            }
        else
            for (int i = furthest; ; i = parent[i])
                if (heights[i] == (max_height + 1) / 2) {
                    best.push_back(i);
                }
                else if (heights[i] == max_height / 2) {
                    best.push_back(i);
                    break;
                }
        sort(best.begin(), best.end());
        for (int i = 0; i < best.size(); i++) {
            fill(visited.begin(), visited.end(), false);
            max_height = 0;
            dfs(best[i], 0);
            for (int j = 0; j < heights.size(); j++)
                if (heights[j] == max_height)
                    worst.insert(j);
        }

        cout << "Best Roots  :";
        for (auto x : best)
            cout << ' ' << x + 1;
        cout << endl << "Worst Roots :";
        for (auto x : worst)
            cout << ' ' << x + 1;
        cout << endl;
    }
}
