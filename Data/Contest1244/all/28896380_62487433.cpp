#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector< long long > g[N];
long long s[3][3];
long long c[N][3];
long long ans[3];
long long C[N];
int dgin[N];
void dfs(long long u,long long l,long long p)
{
    s[l][0]+=c[u][0],s[l][1]+=c[u][1],s[l][2]+=c[u][2];
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        dfs(x,(l+1)%3,u);
    }
}
void solve(long long u,long long l,long long p)
{
    C[u] = ans[l];
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        solve(x,(l+1)%3,u);
    }
}
int main()
{
    long long n,st,mn = 1e18;
    scanf("%lld",&n);
    for(long long i=0;i<3;i++)  for(long long j=1;j<=n;j++)   scanf("%lld",&c[j][i]);
    for(long long i=1,u,v;i<n;i++)    scanf("%lld %lld",&u,&v),g[u].push_back(v),g[v].push_back(u),++dgin[v],++dgin[u];
    for(long long i=1;i<=n;i++)   if(dgin[i]>=3)  return puts("-1"),0;
    for(long long i=1;i<=n;i++)
    {
        if(dgin[i]==1)  {st=i,dfs(i,0,0);break;}
    }
    for(long long i=0;i<3;i++)
    {
        for(long long j=0;j<3;j++)
        {
            for(long long k=0;k<3;k++)
            {
                if(i==j||j==k||i==k)    continue;
                if(s[0][i]+s[1][j]+s[2][k]<mn)
                {
                    mn = s[0][i]+s[1][j]+s[2][k];
                    ans[0] = i,ans[1] = j,ans[2] = k;
                }
            }
        }
    }
    solve(st,0,0);
    printf("%lld\n",mn);
    for(long long i=1;i<=n;i++) printf("%lld ",C[i]+1);
    return 0;
}
