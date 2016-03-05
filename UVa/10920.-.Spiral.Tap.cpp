//#include <cstdio>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//long long x;
//vector<long long> A;
//
//int main()
//{
//  while((scanf("%d", &x)) != EOF)
//  {
//    A.push_back(x);
//    sort(A.begin(), A.end());
//    if(A.size() % 2 == 0)
//      printf("%d\n", (A[A.size()/2] + A[(A.size() / 2) - 1])/2);
//    else
//      printf("%d\n", A[A.size()/2]);
//  }
//}

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    long long k;
    cin >> k;
    while (k--)
    {
   	 long long n, t, m;
   	 cin >> n >> t >> m;
   	 queue <int> left, right;
   	 int a [10010];
   	 long long o [10010];
   	 long long x=0;
   	 for (long long i=0; i<m; i++)
   	 {
   		 int t1;
   		 string p1;
   		 cin >> t1;
   		 cin >> p1;
   		 a[i]=t1;
   		 if (p1=="left")
   			 left.push(t1);
   		 else
   			 right.push(t1);
   	 }
   	 long long tt=0;
   	 string p= "left";
   	 while (x<m)
   	 {
   		 long long counter=0;
   		 if (p=="left")
   		 {
   			 while (!left.empty() && left.front()<=tt && counter<n)
   			 {
   				 int * p= find (a, a+m, left.front());
   				 *(o+(p-a))=tt+t;
   				 left.pop();
   				 counter++;
   				 x++;
   			 }
   			 if (counter !=0 || (!right.empty() && right.front()<=tt))
   			 {
   				 tt+=t;
   				 p="right";
   			 }
   			 else
   			 {
   				 tt++;
         }
       }
   		 else
   		 {
   			 while (!right.empty() && right.front()<=tt && counter<n)
   			 {
   				 int * p= find (a, a+m, right.front());
   				 *(o+(p-a))=tt+t;
   				 right.pop();
   				 counter++;
   				 x++;
   			 }
   			 if (counter !=0 || (!left.empty() &&left.front()<=tt))
   			 {
   				 tt+=t;
   				 p="left";
   			 }
   			 else
   			 {
   				 tt++;
   			 }
   		 }
   	 }
   	 for (int i=0; i<m; i++)
   		 cout << o[i] << endl;
   	 if (k)
   		 cout << endl;
    }
    return 0;
}


