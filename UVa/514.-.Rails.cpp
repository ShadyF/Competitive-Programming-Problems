#include <cstdio>
#include <stack>
using namespace std;

int N, A[100000], stock, k, flag;
int main()
{
  while(scanf("%d", &N) == 1)
  {
    if (N == 0)
      return 0;
    scanf("%d", &A[1]);
    while(A[1] > 0)
    {
      stack<int> s;
      for(int i = 2;i <= N; i++)
        scanf("%d", &A[i]);
      stock = 1, k = 1, flag = true;
      while(!s.empty() || stock <= N)
      {
        if(A[k] == stock)
          stock++, k++;
        else if (!s.empty() && A[k] == s.top())
          s.pop(), k++;
        else if (stock > N && !s.empty())
        {
          flag = false;
          break;
        }
        else
          s.push(stock), stock++;
      }
      printf("%s", (flag) ? "Yes\n" : "No\n");
      scanf("%d", &A[1]);
    }
    printf("\n");
}
  return 0;
}