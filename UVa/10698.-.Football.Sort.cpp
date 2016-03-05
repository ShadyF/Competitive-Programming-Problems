#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

int c_time, n, dt, m, t, cargo;
bool left;
char c;
int tests;
int main()
{
  scanf("%d", &tests);
  while(tests--)
  {
    scanf("%d %d %d", &n, &dt, &m);
    queue<int> ql;
    queue<int> qr;
    c_time = 0;
    left = 1;
    while(m--)
    {
      cargo = 0;
      scanf("%d %c%*s", &t, &c);
      if(c == 'l')
        ql.push(t);
      else qr.push(t);
      if(!qr.empty() && !ql.empty() && qr.front() > c_time && ql.front() > c_time)
      {
        if(qr.front() > ql.front())
        {
          c_time += qr.front();
          if (left)
          {
            c_time += dt;
            left = !left;
          }
        }
        else
        {
          c_time += ql.front();
          if(!left)
          {
            c_time += dt;
            left = !left;
          }
          }
      }
      if (left)
      {
        left = !left;
        while(!ql.empty() && cargo < n &&  ql.front() <= c_time)
        {
          ql.pop();
          printf("%d\n", c_time+dt);
          cargo++;
        }
      }
      else
      {
        left = !left;
        while(!qr.empty() && cargo < n && qr.front() <= c_time)
        {
          qr.pop();
          printf("%d\n", c_time+dt);
          cargo++;
        }
      }
      c_time += dt;
    }
  }
}