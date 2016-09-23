#include <bits/stdc++.h>

using namespace std;

int n;
long long result;
string line;
int given_row[16];
long long memo[16][16];
char row_char;

long long solve(int row, int col) {
    if (col == n-1)
        return 1;
    if (memo[row][col] != -1)
        return memo[row][col];

    long long ans = 0;

    if (given_row[col + 1] == -1)
        for (int i = 0; i < n; i++) {
            if (i != row + 1 && i != row && i != row - 1)
                ans += solve(i, col + 1);
        }
    else if (given_row[col + 1] != row - 1 && given_row[col + 1] != row + 1 &&
             given_row[col + 1] != row)
        ans += solve(given_row[col + 1], col + 1);


    return memo[row][col] = ans;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> line) {
        stringstream s(line);
        n = 0;
        memset(given_row, -1, sizeof(given_row));
        memset(memo, -1, sizeof(memo));
        while (s.good()) {
            s >> row_char;
            if (row_char != '?') {
                if (isdigit(row_char))
                    given_row[n] = row_char - '0' - 1;
                else
                    given_row[n] = row_char - 'A' + 10 - 1;
            }
            n++;
        }
        n--;
        result = 0;
        if (given_row[0] == -1)
            for (int i = 0; i < n; i++)
                result += solve(i, 0);
        else
            result += solve(given_row[0], 0);

        cout << result << endl;
    }
}
