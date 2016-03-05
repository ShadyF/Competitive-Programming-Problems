#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char s[100];
bool x;
int main()
{
  while(gets(s))
  {
    if(!strcmp(s, "#"))
      break;
    x = next_permutation(s, s+strlen(s) );
    if (x)
      printf("%s\n", s);
    else
      printf("No Successor\n");
  }
  return 0;
}