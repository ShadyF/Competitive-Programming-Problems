#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int T;
string vars;
string constraints_s;
map<int, vector<int>> constraints;
vector<bool> used;
string current_string;
bool output_exists;

void backtrack(int index)
{

    if(index >= vars.size())
        return;

    if(!constraints[index].empty())
        for(int i = 0; i < constraints[index].size(); i++)
            if(used[constraints[index][i]])
                return;

    used[index] = true;
    current_string.push_back(vars[index]);

    if(current_string.size() == vars.size())
    {
        for(int i = 0; i < current_string.size() - 1; i++)
            cout << current_string[i] << " ";
        cout << current_string[current_string.size() - 1] << endl;
        used[index] = false;
        current_string.pop_back();
        output_exists = true;
        return;
    }

    for(int i = 0; i < vars.size(); i++)
        if(!used[i] && index != i)
            backtrack(i);
    used[index] = false;
    current_string.pop_back();
}
int main()
{
    cin >> T;
    cin.get();
    for(int i = 0; i < T; i++)
    {
        constraints.clear();
        output_exists = false;
        cin.get();
        getline(cin, vars);
        getline(cin, constraints_s);
        vars.erase(std::remove(vars.begin(), vars.end(), ' '), vars.end());
        constraints_s.erase(std::remove(constraints_s.begin(), constraints_s.end(), ' '), constraints_s.end());

        sort(vars.begin(), vars.end());

        for(int i = 0; i < constraints_s.size(); i = i + 3)
            constraints[vars.find(constraints_s[i])].push_back(vars.find(constraints_s[i+2]));

        used.resize(vars.size(), false);
        for(int i = 0; i < vars.size(); i++)
        {
            current_string = "";
            backtrack(i);
        }
        if(!output_exists)
            cout <<"NO\n";
        if(i != T - 1) cout << endl;
    }
}
