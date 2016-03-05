#include <cstdio>
#include <bitset>

using namespace std;

long long n, m;
long long start, endd, interval;
bool trig;
bitset<1000010> b(0);

inline void work()
{
  b = 0;
  while(n--)
  {
    trig = 0;
    scanf("\n%lld %lld", &start, &endd);
    for(start; start < endd; start++)
    {
      if (b[start] == 1)
      {
        while(n--)
          scanf("\n%lld %lld", &start, &endd);
        while(m--)
          scanf("\n%lld %lld %lld", &start, &endd, &interval);
        printf("CONFLICT\n");
        return;
      }
      else
        b[start] = 1;
    }
  }
  while(m--)
  {
    trig = 0;
    scanf("\n%lld %lld %lld", &start, &endd, &interval);
    for(start; start <= 1000000; start += interval, endd += interval)
    {
      for(long long i = start; i < endd; i++)
        {
          if(b[i] == 1)
          {
            while(m--)
              scanf("\n%lld %lld %lld", &start, &endd, &interval);
            printf("CONFLICT\n");
            return;
          }
          else
            b[i] = 1;
      }
    }
  }
  printf("NO CONFLICT\n"); 
}
int main()
{
  while((scanf("\n%lld %lld", &n, &m)) != EOF)
  {
    if (n != 0 || m != 0)
      work();
    else
      return 0;
  }
}