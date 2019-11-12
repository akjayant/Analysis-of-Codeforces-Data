#include <bits/stdc++.h>
#define rest 1000000007
using namespace std;
int a[305][305],nr,i,j,n;

int main()
{
   cin>>n;
   for(i=1;i<=n;i++){
      if(i%2==0){
         for(j=1;j<=n;j++)
            a[j][i]=++nr;
      }
      else {
         for(j=n;j>=1;j--)
            a[j][i]=++nr;
      }

            }
      for(i=1;i<=n;i++){
         for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
         cout<<"\n";
      }

}
