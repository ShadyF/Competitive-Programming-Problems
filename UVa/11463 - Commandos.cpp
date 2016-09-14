#include <bits/stdc++.h>

using namespace std;

int T, N, R, s, d, case_num = 0;
int AdjMat[105][105];

const int INF = 0x3f3f3f3f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N >> R;
        memset(AdjMat, INF, sizeof(AdjMat));

        for(int i = 0; i < R; i++)
        {
            int u, v;
            cin >> u >> v;
            AdjMat[u][v] = AdjMat[v][u] = 1;
        }

        for(int k = 0; k < N; k++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    if(i == j)
                        AdjMat[i][j] = 0;
                    else
                        AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        cin >> s >> d;
        int min_val = 0;
        for(int i = 0; i < N; i++)
            if(AdjMat[s][i] != INF && AdjMat[i][d] != INF)
                min_val = max(min_val, AdjMat[s][i] + AdjMat[i][d]);

        cout << "Case " << ++case_num <<": " << min_val << endl;
    }
}
