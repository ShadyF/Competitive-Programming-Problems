#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <sstream>

using namespace std;
int N;
string temp;
vector< vector<int> > AdjList;
vector<int> dist;
queue<int> q;
map<string, int> string_to_int;
vector<string> words;
int counter;

int BFS(int u, int end)
{
    dist.clear(); dist.resize(counter, -1);
    dist[u] = 0;
    while(!q.empty())
        q.pop();
    q.push(u);
    while(!q.empty())
    {
        int vertex_u = q.front(); q.pop();
        for(int i = 0; i < AdjList[vertex_u].size(); i++)
        {
            int v = AdjList[vertex_u][i];
            if(dist[v] == -1)
            {
                dist[v] = dist[vertex_u] + 1;
                q.push(v);
                if(v == end)
                    return dist[v];
            }
        }
    }
    return -1;

}
bool one_char_difference(string s1, string s2)
{
    if(s1.size() != s2.size())
        return false;
    bool flag = false;
    for(int i = 0; i < s1.size(); i++)
        if(s1[i] != s2[i])
            if(flag)
                return false;
            else
                flag = true;
    return true;
}
int main()
{
    cin >> N;
    cin.ignore();
    getline(cin, temp);
    bool first = true;
    while(N--)
    {
        if(!first)
            cout << endl;
        first = false;
        AdjList.clear();
        words.clear();
        string_to_int.clear();
        counter = 0;
        getline(cin, temp);

        while(temp != "*")
        {
            words.push_back(temp);
            string_to_int[temp] = counter++;
            getline(cin, temp);
        }
        AdjList.resize(counter);
        for(int i = 0; i < words.size(); i++)
            for(int j = i + 1; j < words.size(); j++)
                if(one_char_difference(words[i], words[j]))
                {
                    AdjList[string_to_int[words[j]]].push_back(string_to_int[words[i]]);
                    AdjList[string_to_int[words[i]]].push_back(string_to_int[words[j]]);
                }
        getline(cin, temp);
        while(!temp.empty())
        {
            stringstream string_stream(temp);
            string u; string v;
            string_stream >> u;
            string_stream >> v;
            if(u == v)
                cout << u << " " << v << " " << "0" << endl;
            else
                cout << u << " " << v << " " << BFS(string_to_int[u], string_to_int[v]) << endl;
            getline(cin, temp);
        }
    }
}
