#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj_list, memo;
vector<bool> visited;
int T, N, temp, max_count, max_index, case_num = 0;

int DFS(int u)
{
    int tot = 1;
    visited[u] = true;

    if (!visited[adj_list[u]])
        tot += DFS(adj_list[u]);
    visited[u] = false;
    return memo[u] = tot;

}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);

        adj_list.resize(N + 10);
        memo.resize(N + 10, -1);
        visited.resize(N + 10, false);

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &temp);
            scanf("%d", &adj_list[temp]);
        }
        fill(memo.begin(), memo.end(), -1);
        max_count = 0;
        max_index = 0;
        for (int i = 1; i <= N; i++)
        {
            if (memo[i] == -1)
                DFS(i);
            if (memo[i] > max_count)
            {
                max_count = memo[i];
                max_index = i;
            }
        }
        printf("Case %d: %d\n", ++case_num, max_index);
    }
}