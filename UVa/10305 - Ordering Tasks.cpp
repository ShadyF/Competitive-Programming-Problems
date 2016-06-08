#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

vector< vector<int> > adj_list;
bool visited[115];
int n, m;
stack<int> TopSort;
void topologicalSort(int u)
{
    if(u > n)
        return;
    visited[u] = true;
    for(int i = 0; i < adj_list[u].size(); i++)
        if(!visited[adj_list[u][i]])
            topologicalSort(adj_list[u][i]);

    TopSort.push(u);
}

int main()
{
    while(scanf("%d %d", &n, &m) && (n != 0 || m != 0))
    {
        memset(visited, false, sizeof(visited));
        adj_list.clear();
        adj_list.resize(n+5);
        int u, v;
        for(int i = 0 ; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            adj_list[u].push_back(v);
        }
        for(int i = 1; i <= n; i++)
            if(!visited[i])
                topologicalSort(i);
        printf("%d", TopSort.top());
        TopSort.pop();
        while(!TopSort.empty())
        {
            printf(" %d", TopSort.top());
            TopSort.pop();
        }
        printf("\n");
    }
}
