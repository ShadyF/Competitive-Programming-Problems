#include <cstdio>
#include <cstring>

using namespace std;

int A[1010];
int T, n, sum, temp;
int main()
{
  scanf("%d", &T);
  while(T--)
  {
    sum = 0;
    memset(A, 0,sizeof(A));
    scanf("%d", &n);
    scanf("%d", &A[0]);
    for(int i = 1; i<n; i++)
    {
      scanf(" %d", &temp);
      for(int j = 0; j<i;j++)
        sum = (A[j] <= temp) ? sum+1 : sum;
      A[i] = temp;
    }
    printf("%d\n", sum);
  }
}