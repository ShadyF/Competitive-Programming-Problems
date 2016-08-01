#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int R, C, num_bombs;
bool visited[1010][1010];
int dist[1010][1010];
pair<int, int> starting_point, ending_point;
queue<pair<int, int>> q;
pair<int, int> d_dist[4] = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};

int BFS(pair<int, int> starting_p, pair<int, int> ending_p)
{
    if(starting_p == ending_p)
        return 0;
    dist[starting_p.first][starting_p.second] = 0;
    q.push(starting_p);
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> v = make_pair(u.first + d_dist[i].first, u.second + d_dist[i].second);
            if(v.first >= R || v.first < 0 || v.second >= C || v.second < 0)
                continue;
            if (dist[v.first][v.second] == -1)
            {
                dist[v.first][v.second] = dist[u.first][u.second] + 1;
                q.push(v);
                if (v == ending_p)
                    return dist[v.first][v.second];
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> R >> C && ( R != 0 || C != 0 ))
    {
        memset(visited, false, sizeof(visited));
        memset(dist, -1, sizeof(dist));
        cin >> num_bombs;
        for (int i = 0; i < num_bombs; i++)
        {
            int row_num, num_row_bombs, col_num;
            cin >> row_num >> num_row_bombs;
            for (int j = 0; j < num_row_bombs; j++)
            {
                cin >> col_num;
                dist[row_num][col_num] = -2;
            }
        }
        cin >> starting_point.first >> starting_point.second;
        cin >> ending_point.first >> ending_point.second;
        while (!q.empty())
            q.pop();
        cout << BFS(starting_point, ending_point) << endl;
    }
}
