#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

int M;
string O, D;
map<string, int> dist;
map<string, vector<pair<int, string>>> AdjList;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
map<string, vector<string>> lang_words;

int main() {
    while (cin >> M && M != 0) {
        cin >> O >> D;
        AdjList.clear();
        dist.clear();
        lang_words.clear();
        for(int i = 0; i < M; i++)
        {
            string I1, I2, P;
            cin >> I1 >> I2 >> P;

            dist[P] = -1;
            AdjList[P] = vector<pair<int, string>>{};

            if (lang_words.count(I1) > 0)
                lang_words[I1].push_back(P);
            else
                lang_words[I1] = vector<string>{P};

            if (lang_words.count(I2) > 0)
                lang_words[I2].push_back(P);
            else
                lang_words[I2] = vector<string>{P};
        }
        for(auto entry: lang_words)
        {
            vector<string> word_list = entry.second;
            for(int i = 0; i < word_list.size(); i++)
                for(int j = i + 1; j < word_list.size(); j++)
                {
                    if(word_list[i][0] == word_list[j][0])
                        continue;
                    AdjList[word_list[i]].push_back(make_pair(word_list[j].size(), word_list[j]));
                    AdjList[word_list[j]].push_back(make_pair(word_list[i].size(), word_list[i]));
                }
        }
        for(auto word : lang_words[O]) {
            dist[word] = int(word.size());
            pq.push(make_pair(word.size(), word));
        }

        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int d = front.first;
            string u = front.second;
            if (d > dist[u]) continue;
            for(int j = 0; j < AdjList[u].size(); j++)
            {
                auto v = AdjList[u][j];
                if (dist[u] + v.first < dist[v.second] || dist[v.second] == -1)
                {
                    dist[v.second] = dist[u] + v.first;
                    pq.push(make_pair(dist[v.second], v.second));
                }
            }

        }
        int min_val = 50*2200;
        for(auto word : lang_words[D]) {
            if (dist[word] != -1 && dist[word] < min_val)
                min_val = dist[word];
        }
        if (min_val == 50*2200)
            cout << "impossivel\n";
        else
            cout << min_val << endl;

    }

}
