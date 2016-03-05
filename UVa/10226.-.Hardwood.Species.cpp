#include <string>
#include <iostream>
#include <map>

using namespace std;

int N;
int Count;
string s;
map<string, int> m;

int main()
{
  cin >> N;
  cin.ignore();
  getline(cin, s);
  while(N--)
  {
    Count = 0;
    m.clear();
    getline(cin, s);
    while(!s.empty())
    {
      Count++;
      m[s]++;
      getline(cin, s);
    }
    for(auto x : m)
      cout << x.first <<" " << x.second/float(Count) * 100 << endl;
  }

}