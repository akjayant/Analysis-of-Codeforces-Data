#include <bits/stdc++.h>
using namespace std;
int a,b,c,i,n,nr;
int main()
{
   cin>>n;
   for(i=1;i<=n;i++){
      cin>>a>>b>>c;
      nr=0;
      while(b>0&&c>1){
         nr+=3;
         b--;
         c-=2;
      }
      while(a>0&&b>1){
         nr+=3;
         a--;
         b-=2;      }
         cout<<nr<<"\n";
   }

}
