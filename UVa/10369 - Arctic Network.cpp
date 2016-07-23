#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int T, S, P;
vector<pair<double, pair<int, int>>> EdgeList;
vector<pair<int, int> > coords;

class UnionFind
{
public:

    vector<int> p, rank;
    int numSets;

    explicit UnionFind(int N)
    {
        rank.assign(N, 0);
        p.assign(N, 0);
        numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int findSet(int i)
    { return ( p[i] == i ) ? i : ( p[i] = findSet(p[i]) ); }

    bool isSameSet(int i, int j)
    { return findSet(i) == findSet(j); }

    int numDisjoinSets()
    {
        return numSets;
    }

    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            numSets--;
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
    cin >> T;
    while (T--)
    {
        EdgeList.clear();
        coords.clear();
        cin >> S >> P;
        for (int i = 0; i < P; i++)
        {
            int x, y;
            cin >> x >> y;
            coords.push_back(make_pair(x, y));
        }

        for (int i = 0; i < P; i++)
            for (int j = i + 1; j < P; j++)
            {
                int x1 = coords[i].first;
                int y1 = coords[i].second;
                int x2 = coords[j].first;
                int y2 = coords[j].second;
                double w = sqrt(( ( x2 - x1 ) * ( x2 - x1 ) ) + ( ( y2 - y1 ) * ( y2 - y1 ) ));
                EdgeList.push_back(make_pair(w, make_pair(i, j)));
            }

        sort(EdgeList.begin(), EdgeList.end());
        UnionFind UF(P);
        double min_D = 0.0;
        for (int i = 0; i < EdgeList.size() && UF.numDisjoinSets() > S; i++)
        {
            auto front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                if(min_D < front.first)
                    min_D = front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
        }
        cout << setprecision(2) << fixed << min_D <<endl;
    }
}
