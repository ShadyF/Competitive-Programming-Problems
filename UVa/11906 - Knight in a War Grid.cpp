#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

int map[210][210];
bool visited[210][210];
int R, C, M, N, T, W, w_x, w_y;
int even_squares, odd_squares;
int case_num = 0;

void DFS(int x, int y)
{
    visited[x][y] = true;

    set< pair<int, int> > points;

    int dx[8] = {x + M, x + N, x - M, x - N, x + M, x + N, x - M, x - N};
    int dy[8] = {y + N, y + M, y - N, y - M, y - N, y - M, y + N, y + M};
    for (int i = 0; i < 8; i++)
    {
        if ( dx[i] >= 0 && dy[i] >= 0 && map[dx[i]][dy[i]] != -1 )
        {
            points.insert(make_pair(dx[i], dy[i]));
            if ( !visited[dx[i]][dy[i]] )
                DFS(dx[i], dy[i]);
        }

    }
    if(points.size() % 2 == 0)
        even_squares++;
    else
        odd_squares++;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(map, -1, sizeof(map));
        memset(visited, false, sizeof(visited));
        even_squares = 0;
        odd_squares = 0;
        scanf("%d %d %d %d", &R, &C, &M, &N);

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                map[i][j] = 0;

        scanf("%d", &W);

        for (int i = 0; i < W; i++)
        {
            scanf("%d %d", &w_x, &w_y);
            map[w_x][w_y] = -1;
        }
        DFS(0, 0);
        printf("Case %d: %d %d\n", ++case_num, even_squares, odd_squares);
    }
}