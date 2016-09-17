#include <bits/stdc++.h>

using namespace std;

int P, R, case_num = 0;
int AdjMat[55][55];
map<string, int> string_to_int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> P >> R && ( P != 0 || R != 0 ))
    {
        string_to_int.clear();
        memset(AdjMat, 0x3f3f3f3f, sizeof(AdjMat));
        int P_count = 0;
        for (int i = 0; i < R; i++)
        {
            string u, v;
            cin >> u >> v;
            if (string_to_int.find(u) == string_to_int.end())
                string_to_int[u] = P_count++;
            if (string_to_int.find(v) == string_to_int.end())
                string_to_int[v] = P_count++;
            AdjMat[string_to_int[u]][string_to_int[v]] = AdjMat[string_to_int[v]][string_to_int[u]] = 1;
        }
        for (int k = 0; k < P; k++)
            for (int i = 0; i < P; i++)
                for (int j = 0; j < P; j++)
                    if (i == j)
                        AdjMat[i][j] = 0;
                    else
                        AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        bool disconnected = false;
        int max_val = 0;
        for (int i = 0; i < P && !disconnected; i++)
            for (int j = 0; j < P; j++)
            {
                if (AdjMat[i][j] == 0x3f3f3f3f)
                    disconnected = true;
                max_val = max(AdjMat[i][j], max_val);
            }
        cout << "Network " << ++case_num << ": ";
        if (disconnected)
            cout << "DISCONNECTED\n";
        else
            cout << max_val << endl;
        cout << endl;
    }
}
