#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

int n, k;
int T[5];
string floor_line;
vector<int> dist;
vector<vector<pair<int, pair<int, int>>>> AdjList;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int main() {
    while (cin >> n >> k) {
        AdjList.clear();
        AdjList.resize(105);
        dist.clear();
        dist.resize(105, -1);

        for (int i = 0; i < n; i++)
            cin >> T[i];
        cin.ignore();
        for (int i = 0; i < n; i++) {
            string teststring;
            getline(cin, teststring);
            stringstream s(teststring);
            int temp;
            vector<int> temp_array;
            while (s.good()) {
                s >> temp;
                temp_array.push_back(temp + 1);
            }
            for (int j = 0; j < temp_array.size(); j++) {
                if (temp_array[j] == 1)
                    AdjList[0].push_back(make_pair(0, make_pair(temp_array[j], i)));
                for (int k = j + 1; k < temp_array.size(); k++) {
                    AdjList[temp_array[j]].push_back(make_pair(T[i], make_pair(temp_array[k], i)));
                    AdjList[temp_array[k]].push_back(make_pair(T[i], make_pair(temp_array[j], i)));
                }
            }

        }
        dist[0] = 0;
        pq.push(make_pair(0, make_pair(0, -1)));
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int d = front.first;
            auto u = front.second;
            if (d > dist[u.first]) continue;
            int elevator_delay;
            for (int j = 0; j < AdjList[u.first].size(); j++) {
                auto v = AdjList[u.first][j];
                if (u.second == v.second.second || u.second == -1)
                    elevator_delay = 0;
                else
                    elevator_delay = 60;
                if (dist[u.first] + (v.first * abs(u.first - v.second.first)) + elevator_delay < dist[v.second.first] || dist[v.second.first] == -1) {
                    dist[v.second.first] = dist[u.first] + (v.first * abs(u.first - v.second.first)) + elevator_delay;
                    pq.push(make_pair(dist[v.second.first], make_pair(v.second.first, v.second.second)));
                }
            }
        }

        if (dist[k+1] == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << dist[k+1] << endl;


    }

}
