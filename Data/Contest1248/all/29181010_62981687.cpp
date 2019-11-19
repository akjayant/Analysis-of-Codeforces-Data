#include <bits/stdc++.h>
using namespace std;

int main()
{
          int t;
          cin >> t;
          while(t--)
          {
                    int n,m;
                    cin >> n;
                    long long n1=0,n2=0,m1=0,m2=0,t;
                    for(int i=0;i<n;i++)
                    {
                              scanf("%lld",&t);
                              if(abs(t)%2)
                                        n1++;
                              else
                                        n2++;
                    }
                    cin >> m;
                    for(int i=0;i<m;i++)
                    {
                              scanf("%lld",&t);
                              if(abs(t)%2)
                                        m1++;
                              else
                                        m2++;
                    }
                    printf("%lld\n",n1*m1+n2*m2);
          }
          return 0;
}
