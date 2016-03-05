#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

char x;
char s[1100];
bool flag;
int counter = 1;
vector<stack<char>> stacks;
int main()
{
  while(true)
  {
    stacks.clear();
    gets(s);
    if(strcmp(s, "end"))
    {
      for(int i = 0; i < strlen(s); i++)
      {
        flag = false;
        for(auto &stack : stacks)
          if(s[i] <= stack.top())
          {
            stack.push(s[i]);
            flag = true;
            break;
          }
        if(!flag)
        {
            stack<char> k;
            k.push(s[i]);
            stacks.push_back(k);
        }
      }
      printf("Case %d: %d\n", counter++, stacks.size());
    }
    else
      return 0;
  }
}