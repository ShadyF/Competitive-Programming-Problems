#include <cstdio>
#include <cstring>
using namespace std;

char c[210];
int A[5][5];
int Case = 1;
int x, y;
char t;
int main()
{
  gets(c);
  while(!feof(stdin))
  {
    memset(A, 0, sizeof(A));
    for(int i = 0; i < strlen(c); i++)
    {
      t = c[i] - 'a';
      x = t/3 + 1;
      y = t%3 + 1;
      A[x][y]++;
      A[x][y + 1]++;
      A[x][y - 1]++;
      A[x + 1][y]++;
      A[x - 1][y]++;
    }
    printf("Case #%d:\n", Case++);
    for(int i = 1; i < 4; i++)
    {
      for(int j = 1; j < 4; j++)
        printf("%d ", A[i][j] % 10);
      printf("\n");
    }
    gets(c);
  }
}