#include <iostream>
#include <cstring>

using namespace std;

int T, N, alive_ships, case_num = 0;
char map[160][160];
bool visited[160][160];

int di[] = {1, 0, -1, 0};
int dj[] = {0, -1, 0, 1};

int floodfill(int x, int y, char tag, char water)
{
    if (x < 0 || x >= N || y < 0 || y >= N)
        return 0;
    if (map[x][y] == water) return 0;

    int ans = 0;
    visited[x][y] = true;
    if (map[x][y] == 'x') ans = 1;
    map[x][y] = '.';
    for (int i = 0; i < 4; i++)
        if (!visited[x + di[i]][y + dj[i]])
            ans += floodfill(x + di[i], y + dj[i], tag, water);
    return ans > 0 ? 1 : 0;

}

int main()
{
    cin >> T;
    while (T--)
    {
        memset(map, -1, sizeof(map));
        memset(visited, false, sizeof(map));

        cin >> N;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> map[i][j];

        alive_ships = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] == 'x')
                {
                    alive_ships++;
                    floodfill(i, j, 'x', '.');
                }
                else if (map[i][j] == '@')
                    alive_ships += floodfill(i, j, '@', '.');
            }

        cout << "Case " << ++case_num << ": " << alive_ships << endl;
    }
}
