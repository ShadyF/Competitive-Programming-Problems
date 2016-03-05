#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  int n, first, second, inc;
  while(scanf("%d %d", &n, &first) != EOF)
  {
    bool flag= true;
    bool check[3010] = {false};
    inc = n - 1;
    while (inc--)
    {
      scanf("%d", &second);
      check[abs(second-first)] = true;
      first = second;
    }
    while(--n > 0)
    {
      if(check[n] == false)
      {
        printf("Not jolly\n");
        flag = false;
        break;
      }
    }
    if(!flag) continue;
    printf("Jolly\n");
  }
}

//int main()
//{
//  int n;
//  while (cin >> n)
//  {
//    int x;
//    int args[3010];
//    bool check[3010] = {false};
//    bool flag = true;;
//    for(int i = 0; i < n; i++)
//    {
//      cin >> x;
//      args[i] = x;
//    }
//
//    for(int i = 0; i < n - 1; i++)
//      check[abs(args[i+1] - args[i])] = true;
//
//    for(int i = 1; i < n - 1; i++)
//      if(check[i] == false)
//      {
//        cout << "Not jolly\n";
//        flag = false;
//        break;
//      }
//    if (!flag) continue;
//    cout << "Jolly\n";
//  }
//};

