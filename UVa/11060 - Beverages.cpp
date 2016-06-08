#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int N, M, case_num = 0;
string temp;
vector<string> beverages;
vector<int> in_degree;
vector<vector<int> > adj_list;
vector<string> answer;
map<string, int> beverages_to_int;
priority_queue<int, vector<int>, std::greater<int> > beverage_queue;

int main()
{
    while (cin >> N)
    {
        beverages.clear();
        beverages_to_int.clear();
        in_degree.clear();
        adj_list.clear();
        answer.clear();
        while (!beverage_queue.empty())
            beverage_queue.pop();

        in_degree.resize(N, 0);
        adj_list.resize(N);

        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            beverages.push_back(temp);
            beverages_to_int[temp] = i;
        }
        cin >> M;
        string u, v;
        for (int i = 0; i < M; i++)
        {
            cin >> u >> v;
            adj_list[beverages_to_int[u]].push_back(beverages_to_int[v]);
            in_degree[beverages_to_int[v]]++;
        }
        for (int i = 0; i < N; i++)
        {
            if (in_degree[i] == 0)
                beverage_queue.push(i);
        }

        while (!beverage_queue.empty())
        {
            int current_node = beverage_queue.top();
            answer.push_back(beverages[current_node]);
            beverage_queue.pop();
            for (int i = 0; i < adj_list[current_node].size(); i++)
            {
                in_degree[adj_list[current_node][i]]--;
                if (in_degree[adj_list[current_node][i]] == 0)
                    beverage_queue.push(adj_list[current_node][i]);
            }
        }

        cout << "Case #" << ++case_num << ": Dilbert should drink beverages in this order:";
        for (int i = 0; i < answer.size(); i++)
            cout << " " << answer[i];
        cout << "." << endl << endl;
    }
}
