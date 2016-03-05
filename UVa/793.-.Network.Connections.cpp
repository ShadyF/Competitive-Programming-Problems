#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

typedef vector<int> vi;
class UnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
UnionFind(int N) { rank.assign(N + 1, 0);
p.assign(N + 1, 0); for (int i = 0; i < N; i++) p[i] = i; }
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { // if from different set
        int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
    else { p[x] = y;
    if (rank[x] == rank[y]) rank[y]++; }
} } };

int n, s, u, comps, i, j;
string input;
int main()
{
  cin >> n;
  while(n--)
  {
    s = u = 0;
    cin >> comps;
    UnionFind UF(comps);
    cin.ignore();
    while(getline(cin, input))
    {
      stringstream stream(input);
      stream >> input;
      if(input.empty())
        break;
      if(input == "c")
      {
        stream >> i >> j;
        UF.unionSet(i, j);
      }
      else if(input == "q")
      {
        stream >> i >> j;
        if(UF.isSameSet(i, j))
          s++;
        else
          u++;
      }
    }
    printf("%d,%d\n", s, u);
    if(n) printf("\n"); //ty ewais
  }
}