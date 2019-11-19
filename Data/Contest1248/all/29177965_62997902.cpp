#include <bits/stdc++.h>
using namespace std;


long long n,m,g[100005],f[100005],mod;
bool kt;
int main()
{ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("fuck.inp","r",stdin);
    //freopen("fuck.out","w",stdout);
    cin>>n>>m;
   f[0]=2;f[1]=2;f[2]=4;mod=1000000007;
   for (int i=3;i<=100000;++i) f[i]=(f[i-1]+f[i-2])%mod;
   g[1]=f[n];
   for (int i=2;i<=m;++i) g[i]=(g[i-1]+f[i-2])%mod;
   cout<<g[m];
}
