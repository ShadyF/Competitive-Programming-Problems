#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cases, N, E, T, M, count;
vector<int> dist;
vector<vector<pair<int, int>>> AdjList;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> cases;
    bool flag = true;
    while (cases--)
    {
        if(flag)
            flag = false;
        else
            cout << endl;
        cin >> N >> E >> T >> M;
        AdjList.clear();
        AdjList.resize(N);
        dist.clear();
        dist.resize(N, -1);
        for (int i = 0; i < M; i++)
        {
            int a, b, t;
            cin >> a >> b >> t;
            AdjList[b - 1].push_back(make_pair(a - 1, t));      // reverse the edge direction
        }
        count = 0;
        pq.push(make_pair(0, E-1));
        dist[E-1] = 0;
        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;
            for (int i = 0; i < AdjList[u].size(); i++)
            {
                auto v = AdjList[u][i];
                if (dist[u] + v.second < dist[v.first] || dist[v.first] == -1)
                {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(make_pair(dist[v.first], v.first));
                }
            }
        }
        count = 0;

        for(int i = 0; i < N; i++)
            if (dist[i] <= T && dist[i] != -1) count++;

        cout << count << endl;
    }
}
