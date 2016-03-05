#include <cstdio>
#include <cmath>
using namespace std;
int A[1010];
int B[1000010];
int n, m, iter = 0, temp, b_length, num;
int main()
{
  while(scanf("%d", &n))
  {
    if(!n)
      break;
    b_length = 0;
    for(int i = 0; i<n; i++)
      scanf("%d", &A[i]);
    for(int i = 0; i<n; i++)
      for(int j = i+1; j<n; j++)
        B[b_length++] = A[i] + A[j];

    scanf("%d", &m);
    printf("Case %d:\n", ++iter);
    while(m--)
    {
      scanf("%d", &num);
      temp = B[0];
      for(int i = 0; i<b_length; i++)
        temp = ( abs(num - B[i]) < abs(num - temp) ) ? B[i] : temp;
      printf("Closest sum to %d is %d.\n", num, temp);
    }
  }
}