#include <map>
#include <cstdio>

using namespace std;

int N;
int x;
int k;
int main()
{
	scanf("%d", &N);
	while (N--)
	{
		map<char,long> m;
		char c;
		long temp;
		long cost = 0;
		scanf("%d\n", &k);
		while(k--)
		{
			scanf("%c %d\n", &c, &temp);
			m.insert(make_pair(c, temp));
		}
		scanf("%d\n", &x); //useless
		while(x)
    {
      scanf("%c", &c);
      if(c == '\n')
        x--;
			else if(m.find(c) != m.end())
			{
				cost += m[c];			
			}
    }
		printf("%.2lf$\n", (float)(cost/100.0));
  }
}