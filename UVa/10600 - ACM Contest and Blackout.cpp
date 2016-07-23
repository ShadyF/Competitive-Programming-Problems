#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int T, V, E;
vector<pair<double, pair<int, int>>> EdgeList;
vector<int> flag_vector;

class UnionFind
{
public:

    vector<int> p, rank;
    int numSets;
    int num;
    explicit UnionFind(int N)
    {
        num = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }

    void reset()
    {
        rank.assign(num, 0);
        p.assign(num, 0);
        numSets = num;
        for (int i = 0; i < num; i++) p[i] = i;
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
        flag_vector.clear();
        cin >> V >> E;
        int max_weight = 0;
        for (int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            EdgeList.push_back(make_pair(w, make_pair(u - 1, v - 1)));
            max_weight += w;
        }
        sort(EdgeList.begin(), EdgeList.end());
        int best_result = 0;
        int second_best_result = max_weight;
        UnionFind UF(V);
        for (int i = 0; i < E; i++)
        {
            auto front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                best_result += front.first;
                flag_vector.push_back(i);
                UF.unionSet(front.second.first, front.second.second);
            }
        }
        for (int i = 0; i < flag_vector.size(); i++)
        {
            int skip = flag_vector[i];
            int temp_result = 0;
            UF.reset();
            for (int j = 0; j < E; j++)
            {
                auto front = EdgeList[j];
                if (j != skip && !UF.isSameSet(front.second.first, front.second.second))
                {
                    temp_result += front.first;
                    UF.unionSet(front.second.first, front.second.second);
                }
            }
            if(UF.numDisjoinSets() == 1)
                second_best_result = min(second_best_result, temp_result);
        }

        cout << best_result << " " << second_best_result << endl;
    }
}
