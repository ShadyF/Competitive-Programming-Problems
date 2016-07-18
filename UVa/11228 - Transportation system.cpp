#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <cmath>
using namespace std;

int T, n, r;
vector< pair<int, int> > coords;
vector< vector< pair<double, int> > > AdjList;
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > pq;
vector<bool> taken;
double roads_cost, rails_cost;
int states;
int case_num = 1;

void process(int u)
{
    taken[u] = true;
    for(int i = 0; i < AdjList[u].size(); i++)
    {
        pair<double, int> v = AdjList[u][i];
        if(!taken[v.second]) pq.push(v);
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> r;
        coords.clear();
        AdjList.clear(); AdjList.resize(n);
        taken.assign(n, false);
        for(int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            coords.push_back(make_pair(x, y));
        }
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                int x1 = coords[i].first;
                int y1 = coords[i].second;
                int x2 = coords[j].first;
                int y2 = coords[j].second;
                double w = sqrt( ( (x2 - x1) * (x2-x1) )  + ((y2-y1) * (y2-y1)));
                AdjList[i].push_back(make_pair(w, j));
                AdjList[j].push_back(make_pair(w, i));
            }
        process(0);
        roads_cost = 0; rails_cost = 0; states = 1;
        while(!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            int u = front.second;
            double w = front.first;
            if(!taken[u])
            {
                if(w <= r)
                {
                    roads_cost += w;
                    process(u);
                }
                else
                {
                    states++;
                    rails_cost += w;
                    process(u);
                }
            }
        }

        cout << "Case #" << case_num++ <<": " << states <<" " << round(roads_cost) <<" " << round(rails_cost) << endl;
    }
}
