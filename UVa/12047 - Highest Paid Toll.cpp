#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, M, s, t, p;
vector<int> S_dist, D_dist;
vector<vector<pair<int, int>>> S_AdjList, D_AdjList;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> s >> t >> p;
        s--, t--;
        S_dist.clear();
        S_dist.resize(N + 1, -1);
        D_dist.clear();
        D_dist.resize(N + 1, -1);
        S_AdjList.clear();
        S_AdjList.resize(N + 1);
        D_AdjList.clear();
        D_AdjList.resize(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            u--, v--;
            S_AdjList[u].push_back(make_pair(c, v));
            D_AdjList[v].push_back(make_pair(c, u));
        }
        S_dist[s] = 0;
        pq.push(make_pair(0, s));
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > S_dist[u]) continue;
            for (int i = 0; i < S_AdjList[u].size(); i++) {
                auto v = S_AdjList[u][i];
                if (S_dist[u] + v.first < S_dist[v.second] || S_dist[v.second] == -1) {
                    S_dist[v.second] = S_dist[u] + v.first;
                    pq.push(make_pair(S_dist[v.second], v.second));
                }
            }
        }

        D_dist[t] = 0;
        pq.push(make_pair(0, t));
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > D_dist[u]) continue;
            for (int i = 0; i < D_AdjList[u].size(); i++) {
                auto v = D_AdjList[u][i];
                if (D_dist[u] + v.first < D_dist[v.second] || D_dist[v.second] == -1) {
                    D_dist[v.second] = D_dist[u] + v.first;
                    pq.push(make_pair(D_dist[v.second], v.second));
                }
            }
        }
        int max_val = -1;
        for (int i = 0; i < S_AdjList.size(); i++)
            for (int j = 0; j < S_AdjList[i].size(); j++)
                if (S_dist[i] + S_AdjList[i][j].first + D_dist[S_AdjList[i][j].second] <= p && S_dist[i] != -1 &&
                    D_dist[S_AdjList[i][j].second] != -1)
                    max_val = max(S_AdjList[i][j].first, max_val);

        cout << max_val << endl;

    }
}
