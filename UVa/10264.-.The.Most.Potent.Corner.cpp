#include <cstdio>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

int N;
int A[33000]; //2^15
int results[33000] = {0};
int MAX;
int MAX2;

int main()
{
  while((scanf("%d", &N)) == 1){
  int POW = pow(2,N);
  for(int i = 0; i < POW; i++)
    scanf("%d", &A[i]);

 for(int i = 0; i < POW; i++) {
            int edge_sum = 0;
            for(int j = 0; j < N; j++) {
                int b = i ^ (1 << j);
                edge_sum += A[b];
            }
            results[i] = edge_sum;
        }
 int sum = 0;
  for(int i = 0; i < POW; i++) {
    for(int j = 0; j < N; j++) {
      int b = i ^ (1 << j);
      sum = max(sum, results[b] + results[i]);
    }
  }
  printf("%d\n", sum);
  }
}