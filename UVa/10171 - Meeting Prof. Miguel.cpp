#include <bits/stdc++.h>

using namespace std;

int N;
int YoundAdjMat[50][50], OldAdjMat[50][50], CombAdjMat[50], energy;
char age, direction, u, v, s1, s2;
const int INF = 0x3f3f3f3f;

int main() {
    while (cin >> N && N != 0) {
        memset(YoundAdjMat, INF, sizeof(YoundAdjMat));
        memset(OldAdjMat, INF, sizeof(OldAdjMat));
        memset(CombAdjMat, INF, sizeof(CombAdjMat));

        for (int i = 0; i < N; i++) {
            cin >> age >> direction >> u >> v >> energy;

            int u_int = u - 65, v_int = v - 65;
            if (age == 'Y') {
                YoundAdjMat[u_int][v_int] = energy;
                if (direction == 'B')
                    YoundAdjMat[v_int][u_int] = energy;
            } else {
                OldAdjMat[u_int][v_int] = energy;
                if (direction == 'B')
                    OldAdjMat[v_int][u_int] = energy;
            }
        }
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++) {
                    if (i == j)
                        YoundAdjMat[i][j] = OldAdjMat[i][j] = 0;
                    else {
                        YoundAdjMat[i][j] = min(YoundAdjMat[i][j], YoundAdjMat[i][k] + YoundAdjMat[k][j]);
                        OldAdjMat[i][j] = min(OldAdjMat[i][j], OldAdjMat[i][k] + OldAdjMat[k][j]);
                    }
                }

        cin >> s1 >> s2;
        int s1_int = s1 - 65;
        int s2_int = s2 - 65;
        int min_val = INF;

        for (int i = 0; i < N; i++) {
            if (YoundAdjMat[s1_int][i] + OldAdjMat[s2_int][i] < CombAdjMat[i]) {
                CombAdjMat[i] = YoundAdjMat[s1_int][i] + OldAdjMat[s2_int][i];
                min_val = min(min_val, CombAdjMat[i]);
            }
        }
        if (min_val == INF)
            cout << "You will never meet.\n";
        else {
            cout << min_val;
            for (int i = 0; i < N; i++)
                if (CombAdjMat[i] == min_val)
                    cout << " " << char(i + 65);
            cout << endl;
        }

    }
}
