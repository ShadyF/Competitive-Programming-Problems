//WORKS BUT REPORTS WRONG ANSWER ON UVA BECAUSE THE POSSIBLE OUTPUTS ARE SIMPLY 
//TOO LARGE FOR C++'S LARGEST DATA TYPES
#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long int number, sum[101], result, temp, k;
vector<long long int> sequence;

int main()
{
  while(scanf("%d", &temp) != EOF)
  {
    result = -999999;
    memset(sum, -1, sizeof(sum));
    k = 0;
    sequence.clear();
    while(temp != -999999)
    {
      sequence.push_back(temp);
      scanf("%lld", &temp);
    }
    for(int i = 0; i < sequence.size(); i++)
    {
      for(int j = k; j >= 0; j--)
      {
        if(sum[j] == -1)
          sum[j] = 1;
        sum[j] *= sequence[i];
      }
      result = max(result, *max_element(sum, sum+k+1));
      if(sequence[i] < 0)
        k++;
      else if(sequence[i] == 0)
      {
        k = 0;
        sum[0] = 1;
      }
    }
    printf("%lld\n", result);
  }
}
