#include <bits/stdc++.h>

using namespace std;

int u, v, case_num = 0;
int AdjMat[105][105];

bitset<105> pages;

int main() {
    while (cin >> u >> v && (u != 0 || v != 0)) {
        memset(AdjMat, 0x3f3f3f3f, sizeof(AdjMat));
        pages.reset();
        pages[u] = pages[v] = true;
        AdjMat[u][v] = 1;
        while (cin >> u >> v && (u != 0 || v != 0)) {
            pages[u] = pages[v] = true;
            AdjMat[u][v] = 1;
        }
        int V = (int) pages.count();

        for (int k = 1; k <= 101; k++)
            for (int i = 1; i <= 101; i++)
                for (int j = 1; j <= 101; j++)
                    if (i != j)
                        AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        float count = 0;
        for (int i = 1; i <= 101; i++)
            for (int j = 1; j <= 101; j++)
                count = AdjMat[i][j] != 0x3f3f3f3f ? count + AdjMat[i][j] : count;

        cout << "Case " << ++case_num << ": average length between pages = " << setprecision(3) << fixed
             << count / float((V * (V - 1))) << " clicks" << endl;
    }
}
