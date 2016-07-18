#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
    vector<int> p, rank;

public:
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

int V, E;
long long int result;
long long int total_amount;
vector<pair<int, pair<int, int>>> EdgeList;

int main()
{
    while (cin >> V >> E && ( V != 0 || E != 0 ))
    {
        EdgeList.clear();
        total_amount = 0;
        for (int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            EdgeList.push_back(make_pair(w, make_pair(u, v)));
            total_amount += w;
        }
        sort(EdgeList.begin(), EdgeList.end());
        result = 0;
        UnionFind UF(V);
        for (int i = 0; i < E; i++)
        {
            auto front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                result += front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
        }
        cout << total_amount - result << endl;
    }
}
