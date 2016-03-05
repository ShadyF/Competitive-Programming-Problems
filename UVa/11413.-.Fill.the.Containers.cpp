#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int vessels, containers, temp;
vector<int> capacity;
bool canFill(int target)
{
  int current_container = 0;
  int current_capacity = 0;
  for(int i = 0; i < vessels; i++)
  {
    if(current_container >= containers)
      return false;
    if(current_capacity + capacity[i] <= target)
      current_capacity += capacity[i];
    else if(current_capacity != 0)
    {
      current_container++;
      i--;
    }
    else
      return false;
  }
  return true;
}

int main()
{
  while(scanf("%d %d", &vessels, &containers) != EOF)
  {
    capacity.clear();
    for(int i = 0; i < vessels; i++)
    {
      scanf("%d", &temp);
      capacity.push_back(temp);
    }
    int hi = 0;
    for(int i = 0; i < capacity.size(); i++)
      hi += capacity[i];
    hi++;
    int lo = 0;
    int ans = 0;
    int mid = 0;
    for(int i = 0; i < 50; i++)
    {
      mid = (lo+hi)/2;
      //printf("%d\n", mid);
      if(canFill(mid)) {ans = mid; hi = mid;}
      else lo = mid;
    }

    printf("%d\n", ans);
  }
}
