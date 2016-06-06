#include <iostream>
#include <cstring>

using namespace std;

int N, M, X, Y;

char map[25][25];
bool visited[25][25];
bool already_acquired;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int max_count, current_count;

int mod(int k, int n)
{
    return ( ( k %= n ) < 0 ) ? k + n : k;
}

int floodfill(int x, int y, char land, char dot)
{
    if (x < 0 || x > M) return 0;
    if (map[x][y] != land) return 0;
    if (x == X && y == Y)
        already_acquired = true;

    visited[x][y] = true;
    int ans = 1;
    map[x][y] = dot;

    for (int i = 0; i < 4; i++)
        if (!visited[x + dr[i]][mod(y + dc[i], N)])
            ans += floodfill(x + dr[i], mod(y + dc[i], N), land, dot);

    return ans;
}

int main()
{
    while (cin >> M >> N)
    {
        memset(map, -1, sizeof(map));
        memset(visited, false, sizeof(visited));
        max_count = 0;

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> map[i][j];

        cin >> X >> Y;
        char ll = map[X][Y];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (map[i][j] == ll)
                {
                    already_acquired = false;
                    current_count = 0;
                    current_count = floodfill(i, j, ll, '}');
                    if (current_count > max_count && !already_acquired)
                        max_count = current_count;
                }

        cout << max_count << endl;
    }
}
