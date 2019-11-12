#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int mg[1004];

int main()
{
    int k,i,j,n,u,res;

    cin>>k;

    while(k--)
    {
        cin>>n;
      for(i=1;i<=n;i++)  cin>>mg[i];

      res=0;
      for(i=n;i>=1;i--)
      {
          u=0;
          for(j=1;j<=n;j++)
          {
              if(mg[j]>=i) u++;
          }

          if(u>=i) {res=i;  break;}
      }
      cout<<res<<endl;
    }

    return 0;
}
