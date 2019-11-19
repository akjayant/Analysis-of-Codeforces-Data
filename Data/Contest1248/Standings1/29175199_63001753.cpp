#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+5,p=1e9+7;
ll f[N][2][2],g[N][2][2];
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    f[1][1][0]=f[1][0][0]=1;
    for(int i=2;i<=m;i++)
    {
        f[i][0][0]=(f[i-1][1][0]+f[i-1][1][1])%p;
        f[i][0][1]=f[i-1][0][0];
        f[i][1][0]=(f[i-1][0][0]+f[i-1][0][1])%p;
        f[i][1][1]=f[i-1][1][0];
    }
    //cout<<f[m][0][0]<<" "<<f[m][0][1]<<" "<<f[m][1][0]<<" "<<f[m][1][1]<<endl;
    ll sum=f[m][0][0]+f[m][1][1]+f[m][1][0]+f[m][0][1];
    g[1][1][0]=g[1][0][0]=1;
    for(int i=2;i<=n;i++)
    {
        g[i][0][0]=(g[i-1][1][0]+g[i-1][1][1])%p;
        g[i][0][1]=g[i-1][0][0];
        g[i][1][0]=(g[i-1][0][0]+g[i-1][0][1])%p;
        g[i][1][1]=g[i-1][1][0];
    }
    ll sum2=g[n][0][0]+g[n][1][1]+g[n][1][0]+g[n][0][1];
    cout<<(sum-2+sum2+p)%p<<endl;
}
