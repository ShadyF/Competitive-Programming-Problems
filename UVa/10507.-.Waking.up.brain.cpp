//how the fuck can this be solved using UDS?
#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
class UnionFind { // OOP style
public: vi p, rank; // remember: vi is vector<int>
UnionFind(int N) { rank.assign(N + 1, 0);
p.assign(N + 1, 0); for (int i = 0; i < N; i++) p[i] = i; }
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j) && ((rank[i] < rank[j] + 1) || (rank[j] < rank[i] + 1));}
void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { // if from different set
        int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
    else { p[x] = y;
    if (rank[x] == rank[y]) rank[y]++; }
} } };

int N, M, years, counter;
string waken;
string s;
set<int> st;
vector<int> removed;
bool flag;
int main()
{
  while(cin >> N)
  {
    s.clear();
    cin >> M;
    UnionFind UDS(27);
    cin >> waken;
    while(M--)
    {
      cin >> s;
      UDS.unionSet(s[0] - 65, s[1] - 65);
      st.insert(s[0] - 65);
      st.insert(s[1] - 65);
    }
    st.erase(waken[0] - 65);
    st.erase(waken[1] - 65);
    st.erase(waken[2] - 65);
    years = 0;
    flag = true;
    while(!st.empty() && flag)
    {
      flag = false;
      auto it = st.begin();
      for(int cell : st)
      {
        counter = 0;
        for(int i = 0; i < 27; i++)
          if(cell != i && !st.count(i) && UDS.isSameSet(cell, i))
            counter++;
        if(counter >= 3)
        {
          flag = true;
          removed.push_back(cell);
        }
      }
      years++;
      for(auto x : removed)
      {
        st.erase(x);
      }
    }
    if(st.empty())
      printf("WAKE UP IN, %d, YEARS\n", years);
    else
      printf("THIS BRAIN NEVER WAKES UP\n");
  }

}