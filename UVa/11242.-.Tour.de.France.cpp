#include <cstdio>
#include <algorithm>

using namespace std;

int F[20], B[20];
int f, r, index;
float result , ratios[100 + 10];
int main()
{
  while(scanf("%d", &f))
  {
    if(!f)
      break;
    scanf("%d", &r);
    for(int i = 0; i<f; i++)
      scanf("%d", &F[i]);
    for(int i = 0; i<r; i++)
      scanf("%d", &B[i]);
    index = 0;
    for(int i = 0; i<f; i++)
      for(int j = 0; j<r; j++)
        ratios[index++] = B[j] / float(F[i]);
    sort(begin(ratios), ratios+f*r);
    result = 0.0;
    for(int i = 0; i<f*r-1; i++)
      result = (ratios[i+1]/float(ratios[i]) > result) ? ratios[i+1]/float(ratios[i]) : result;
    printf("%.2f\n", result);
  }
}
