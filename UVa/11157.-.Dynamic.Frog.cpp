#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T, rocks, case_num = 1;
unsigned long long int total_distance, distance_of_rock, last, before;
vector<long long int> difference;
string temp, temp2;
bool flag;

int main()
{
  cin >> T;
  while(T--)
  {
    difference.clear();
    cin >> rocks >> total_distance;
    last = 0;
    flag = false;
    while(rocks--)
    {
      cin >> temp;
      if(flag) {
        difference.push_back(before + stoull(temp.substr(2)) - last);
        flag = false;
      }
      if(temp[0] == 'B') {
        difference.push_back(stoull(temp.substr(2)) - last);
        last=stoull(temp.substr(2));
      }
      else if(temp[0] = 'S') {
        before = stoull(temp.substr(2)) - last;
        last=stoull(temp.substr(2));
        flag = true;
      }
    }
    if(flag)
      difference.push_back(before + total_distance - last);
    else
      difference.push_back(total_distance - last);
    if(difference.empty())
      cout << "Case " << case_num++ <<": " << total_distance <<endl;
    else
      cout << "Case " << case_num++ <<": " << *max_element(difference.begin(), difference.end()) <<endl;
  }
}