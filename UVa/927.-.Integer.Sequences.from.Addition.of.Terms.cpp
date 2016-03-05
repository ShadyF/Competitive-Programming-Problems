#include <cstdio>

using namespace std;
int A[25];
int C, d, k, deg, index, num;
bool found;
long long result;
int main()
{
  scanf("%d", &C);
  while (C--)
  {
    scanf("%d", &deg);
    for(int i = 1; i <= deg + 1; i++)
      scanf("%d", &A[i]);
    scanf("%d", &d);
    scanf("%d", &k);
    index = 1, num = 1, found = false;
    while(!found)
    {
      if(index == k)
      {
        found = true;
        result = num*
    printf("%lld\n", result);
  }
}