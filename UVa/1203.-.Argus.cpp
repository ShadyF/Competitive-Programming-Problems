#include <cstdio>
#include <queue>

using namespace std;
char s[30];
struct query
{
  int id, period, triggertime;
};
class comparison
{
public:
bool operator () (const query &lhs, const query &rhs)
{
  return(lhs.triggertime > rhs.triggertime) ? true : (rhs.triggertime > lhs.triggertime) ? false :  (lhs.id < rhs.id) ? false : true;
}
};
int main()
{
  int id, interval, k;
  priority_queue<query, vector<query>, comparison> q;
  while(scanf("%s", s) && *s != '#')
  {
    scanf("%d %d", &id, &interval);
    query query = {id, interval, interval};
    q.push(query);
  }
  scanf("%d", &k);
  while(k--)
  {
    query x;
    x = q.top();
    printf("%d\n", x.id);
    q.pop();
    x.triggertime += x.period;
    q.push(x);
  }
}