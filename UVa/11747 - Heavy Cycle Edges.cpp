#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> EdgeList;
multiset<int> edges_set;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m && ( n != 0 || m != 0 ))
    {
        EdgeList.clear();
        edges_set.clear();
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            EdgeList.push_back(make_pair(w, make_pair(u, v)));
            edges_set.insert(w);
        }
        sort(EdgeList.begin(), EdgeList.end());
        UnionFind UF(n);
        for (int i = 0; i < m; i++)
        {
            auto front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                edges_set.erase(edges_set.find(front.first));
                UF.unionSet(front.second.first, front.second.second);
            }
        }
        if(edges_set.empty())
            cout << "forest";
        else
        {
            for (auto i = edges_set.begin(); i != prev(edges_set.end()); i++)
                cout << *i << " ";
            cout << *prev(edges_set.end());
        }
        cout << endl;
    }
}
