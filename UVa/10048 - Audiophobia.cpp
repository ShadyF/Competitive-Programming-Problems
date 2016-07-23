#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int E, V, Q;
vector<pair<int, pair<int, int>>> EdgeList;
vector< vector<pair<int, int> > > AdjList;
vector<bool> visited;
int case_num = 1;
int max_w;

class UnionFind
{
public:

    vector<int> p, rank;

    explicit UnionFind(int N)
    {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int findSet(int i)
    { return ( p[i] == i ) ? i : ( p[i] = findSet(p[i]) ); }

    bool isSameSet(int i, int j)
    { return findSet(i) == findSet(j); }

    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else
            {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

void dfs(int u, int v_end, int max_val)
{
    if(u == v_end)
        max_w = max_val;
    visited[u] = true;
    for(int i = 0; i < AdjList[u].size(); i++)
    {
        auto v = AdjList[u][i];
        if(!visited[v.second])
            dfs(v.second, v_end, max(max_val, v.first));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool first = true;
    while (cin >> V >> E >> Q && ( V != 0 || E != 0 || Q != 0 ))
    {
        if(!first)
            cout << endl;
        first = false;
        EdgeList.clear();
        AdjList.clear();
        AdjList.resize(V);
        for(int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            EdgeList.push_back(make_pair(w, make_pair(u-1, v-1)));
        }

        sort(EdgeList.begin(), EdgeList.end());
        UnionFind UF(V);

        for (int i = 0; i < E; i++)
        {
            auto front = EdgeList[i];
            int u = front.second.first;
            int v = front.second.second;
            if (!UF.isSameSet(u, v))
            {
                UF.unionSet(u, v);
                AdjList[u].push_back(make_pair(front.first, v));
                AdjList[v].push_back(make_pair(front.first, u));
            }
        }

        cout << "Case #" << case_num++ << endl;
        for(int i = 0; i < Q; i++)
        {
            visited.clear();
            visited.resize(V, false);
            max_w = 0;
            int u, v;
            cin >> u >> v;
            dfs(u-1, v-1, 0);
            if(max_w == 0)
                cout << "no path" << endl;
            else
                cout << max_w << endl;
        }
    }
}
