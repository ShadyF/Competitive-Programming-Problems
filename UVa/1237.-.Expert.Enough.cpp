#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s;
string M[10100];
int L[10100], H[10100];
int T, D, Q, P;
bool found;
int main()
{
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &D);
    for(int i = 0; i<D; i++)
      cin >> M[i] >> L[i] >> H[i];
    scanf("%d", &Q);
    while (Q--)
    {
      found = false;
      scanf("%d", &P);
      for(int i = 0; i<D; i++)
        if(P >= L[i] && P <= H[i])
        {
          if(found)
          {
            s = "UNDETERMINED";
            break;
          }
          found = true;
          s = M[i];
        }
        if(!found)
          printf("UNDETERMINED\n");
        else
          cout << s <<endl;
    }
    printf("\n");
}
}