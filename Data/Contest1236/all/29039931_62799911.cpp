#include <bits/stdc++.h>

using namespace std;
int f[305][305],N,ct;
int main()
{
    cin>>N;ct=1;
    for (int j=1;j<=N;++j)
   {
    if (j%2==0) ct+=N-1;
    else if (j!=1) ct+=N+1;
     for (int i=1;i<=N;++i)
    {
      f[i][j]=ct;
      if (j%2==0) ct--;else ct++;
    }

   }
   for (int i=1;i<=N;++i)
   {
       for (int j=1;j<=N;++j) cout<<f[i][j]<<' ';cout<<'\n';
   }
    return 0;
}
