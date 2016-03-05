#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int N;
int t, SG, SB;
int temp;
vector<int> G;
vector<int> B;

int main()
{
  scanf("%d", &N);
  while(N--)
  {
    B.clear();
    G.clear();
    scanf("%d %d %d", &t, &SG, &SB);
    while(SG--)
    {
      scanf("%d", &temp);
      G.push_back(temp);
    }
    while(SB--)
    {
      scanf("%d", &temp);
      B.push_back(temp);
    }
    while(!G.empty() && !B.empty())
    {
      sort(G.begin(), G.end(), std::greater<int>());
      sort(B.begin(), B.end(), std::greater<int>());
      int p = t;
      for(int i = 0; i<p && i <B.size() && i < G.size(); i++)
      {
        temp = B[i] - G[i];
        if(temp > 0)
        {
          B[i] = temp;
          G.erase(G.begin() + i);
        }
        else if(temp < 0)
        {
          G[i] = -temp;
          B.erase(B.begin() + i);
        }
        else
        {
          G.erase(G.begin() + i);
          B.erase(B.begin() + i);
          i--;
          p--;
        }
      }
    }
    if(G.empty() && B.empty())
      printf("green and blue died\n");
    else if (G.empty())
    {
      printf("blue wins\n");
      for(auto x : B)
        printf("%d\n", x);
    }
    else
    {
      printf("green wins\n");
      for(auto x : G)
        printf("%d\n", x);
    }
    printf("\n");
  }
}