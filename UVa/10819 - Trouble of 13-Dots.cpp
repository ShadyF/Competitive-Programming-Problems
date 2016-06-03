#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int prices[110];
int FI[110];
int budget, n;
int memo[110][10500];

int dp(int index, int spent)
{

    if ( budget < 1800 )
    {
        if ( spent > budget )
            return -99999999;
    }
    if ( spent > budget + 200 )
            return -99999999;
    
    if ( index >= n )
    {
        if(spent <= 2000 && spent > budget)
            return -99999999;
        return 0;
    }

    if ( memo[index][spent] != -1 )
        return memo[index][spent];

    int ret = max(dp(index + 1, spent), FI[index] + dp(index + 1, spent + prices[index]));
    memo[index][spent] = ret;
    return ret;
}

int main()
{
    while (scanf("%d %d", &budget, &n) != EOF)
    {
        memset(memo, -1, sizeof(memo));

        for (int i = 0; i < n; i++)
            scanf("%d %d", &prices[i], &FI[i]);

        printf("%d\n", dp(0, 0));
    }
}
