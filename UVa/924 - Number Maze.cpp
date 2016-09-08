#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int num_of_mazes, N, M;
int dist[1000][1000];
int maze[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> num_of_mazes;
    while(num_of_mazes--)
    {
        memset(maze, 0, sizeof(maze));
        memset(dist, -1, sizeof(dist));

        cin >> N >> M;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> maze[i][j];
        dist[0][0] = maze[0][0];
        pq.push(make_pair(maze[0][0], make_pair(0, 0)));
        while(!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            int d = front.first;
            auto coords = front.second;
            if(d > dist[coords.first][coords.second])
                continue;
            for(int i = 0; i < 4; i++)
            {
                int x = coords.first + dx[i];
                int y = coords.second + dy[i];
                if(x < 0 || x >= N || y < 0 || y >= M)
                    continue;
                if (dist[coords.first][coords.second] + maze[x][y] < dist[x][y] || dist[x][y] == -1)
                {
                    dist[x][y] = dist[coords.first][coords.second] + maze[x][y];
                    pq.push(make_pair(dist[x][y], make_pair(x, y)));
                }
            }
        }

        cout << dist[N-1][M-1] << endl;
    }
}
