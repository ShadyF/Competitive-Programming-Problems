#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int p1, p2;
queue<pair<int, int>> q;
int dist[2010][2010];
bool mark[2010][2010];
pair<int, int> d_dist[4] = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};

int BFS()
{
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> v = make_pair(u.first + d_dist[i].first, u.second + d_dist[i].second);
            if(v.first < 0 || v.first >= 2000 || v.second < 0 || v.second >= 2000)
                continue;
            if (dist[v.first][v.second] == -1)
            {
                dist[v.first][v.second] = dist[u.first][u.second] + 1;
                if (mark[v.first][v.second])
                    return dist[v.first][v.second];
                q.push(v);
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> p1 && p1 != 0)
    {
        memset(dist, -1, sizeof(dist));
        memset(mark, false,sizeof(mark));
        while (!q.empty())
            q.pop();

        for (int i = 0; i < p1; i++)
        {
            int x, y;
            cin >> x >> y;
            auto current_pair = make_pair(x, y);
            q.push(current_pair);
            dist[x][y] = 0;
        }
        cin >> p2;
        for (int i = 0; i < p2; i++)
        {
            int x, y;
            cin >> x >> y;
            mark[x][y] = true;
        }
        cout << BFS() << endl;
    }
}
