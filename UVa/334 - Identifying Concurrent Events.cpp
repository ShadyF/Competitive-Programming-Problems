#include <bits/stdc++.h>

using namespace std;
int t, NC, NE, NM, case_num = 0;
bool AdjMat[500][500];
map<string, int> string_to_int_map;
vector<string> int_to_string_map;
string E_name;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> NC && NC != 0)
    {
        memset(AdjMat, false, sizeof(AdjMat));
        string_to_int_map.clear();
        int_to_string_map.clear();
        int E_count = 0;
        for (int i = 0; i < NC; i++)
        {
            cin >> NE;
            int prev_index = -1;
            while (NE--)
            {
                cin >> E_name;
                string_to_int_map[E_name] = E_count;
                int_to_string_map.push_back(E_name);
                if (prev_index != -1)
                    AdjMat[prev_index][E_count] = true;
                prev_index = E_count++;
            }
        }
        cin >> NM;
        for (int i = 0; i < NM; i++)
        {
            string u, v;
            cin >> u >> v;
            AdjMat[string_to_int_map[u]][string_to_int_map[v]] = true;
        }
        for (int k = 0; k < E_count; k++)
            for (int i = 0; i < E_count; i++)
                for (int j = 0; j < E_count; j++)
                    AdjMat[i][j] |= ( AdjMat[i][k] & AdjMat[k][j] );

        int num_con_events = 0;
        vector<pair<string, string>> conc_events;
        for (int i = 0; i < E_count; i++)
            for (int j = 0; j < E_count; j++)
                if (!AdjMat[i][j] && !AdjMat[j][i] && i != j)
                {
                    num_con_events++;
                    if (num_con_events > 2)
                        continue;
                    conc_events.push_back({int_to_string_map[i], int_to_string_map[j]});
                }
        if (num_con_events == 0)
            cout << "Case " << ++case_num << ", no concurrent events.\n";
        else
        {

            cout << "Case " << ++case_num << ", " << num_con_events/2 << " concurrent events:\n";
            for(int i = 0; i < conc_events.size() && i < num_con_events/2; i++)
            {
                auto x = conc_events[i];
                cout << "(" << x.first << "," << x.second << ") ";
            }
            cout << endl;
        }
    }
}
