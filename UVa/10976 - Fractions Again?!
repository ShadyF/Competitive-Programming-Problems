#include <cstdio>
#include <vector>

using namespace std;

int k, count, x;
vector<pair<int, int> > pairs;

int main()
{
    while (scanf("%d", &k) != EOF) {
        count = 0;
        pairs.clear();
        for (int i = k + 1; i <= k * 2; i++) {
            if (( i * k ) % ( i - k ) == 0) {
                count++;
                x = ( i * k ) / ( i - k );
                pairs.push_back(make_pair(x, i));
            }
        }
        printf("%d\n", count);
        for(pair <int, int> p : pairs) {
            printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
        }
    }

}
