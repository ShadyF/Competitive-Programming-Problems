#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int L, U, R;
int dist[10000];
int RV[20];
bool path_found;
queue<int> q;
int case_num = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> L >> U >> R && ( L != 0 || U != 0 || R != 0 ))
    {
        memset(dist, -1, sizeof(dist));
        memset(RV, 0, sizeof(RV));
        while (!q.empty())
            q.pop();

        for (int i = 0; i < R; i++)
            cin >> RV[i];

        dist[L] = 0;
        q.push(L);
        path_found = false;
        if(L == U)
            path_found = true;
        while (!q.empty() && !path_found)
        {
            int u = q.front();
            q.pop();
            for(int i = 0; i < R; i++)
            {
                int temp = (u + RV[i]) % 10000;
                if(temp == U)
                {
                    dist[U] = dist[u] + 1;
                    path_found = true;
                    break;
                }
                if(dist[temp] == -1)
                {
                    dist[temp] = dist[u] + 1;
                    q.push(temp);
                }
            }
        }
        cout << "Case " <<++case_num <<": ";
        if(path_found)
            cout << dist[U];
        else
            cout << "Permanently Locked";
        cout << endl;
    }
}
