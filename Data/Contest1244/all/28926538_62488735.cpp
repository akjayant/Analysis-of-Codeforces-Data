#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
const ll inf=1e16;
const int maxn=1e5;
ll a[maxn+5][3];
int n;
vector<int> g[maxn+5];
int output[maxn+5];
int d[maxn+5];
vector<int> id;
ll dp[maxn+5][3][3];
int c[maxn+5];
void dfs(int k,int fa)
{
    id.push_back(k);
    for(auto u:g[k])
    {
        if(u==fa) continue;
        dfs(u,k);
    }
}
void upd(ll &x,ll y)
{
    if(y<x) x=y;
}
int main()
{

    scanf("%d",&n);
    for(int j=0;j<3;++j)
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i][j]);
    for(int i=1;i<n;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        ++d[u];
        ++d[v];
    }
    int mx=0;
    for(int i=1;i<=n;++i) mx=max(mx,d[i]);
    if(mx>=3)
    {
        puts("-1");
        return 0;
    }
    id.push_back(0);
    int S=0;
    for(int i=1;i<=n;++i)
        if(d[i]==1)
    {
        S=i;
        break;
    }
    dfs(S,0);
    assert(id.size()==n+1);
    for(int i=0;i<=n;++i)
        for(int j=0;j<3;++j)
            for(int k=0;k<3;++k)
                dp[i][j][k]=inf;
   // for(int i=1;i<=n;++i) cout<<id[i]<<" ";cout<<endl;
    dp[1][0][0]=a[id[1]][0];
    dp[1][0][1]=a[id[1]][1];
    dp[1][0][2]=a[id[1]][2];
    for(int i=2;i<=n;++i)
        for(int j=0;j<3;++j)
            for(int k=0;k<3;++k)
                if(j!=k)
                {
                    if(i>=3)
                    {


                    int l=3-j-k;
                    upd(dp[i][j][k],dp[i-1][l][j]+a[id[i]][k]);
                    }
                    else
                    {
                        upd(dp[i][j][k],dp[i-1][0][j]+a[id[i]][k]);
                    }
                }
    ll ans=inf;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            ans=min(ans,dp[n][i][j]);
    cout<<ans<<endl;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            if(dp[n][i][j]==ans)
            {
                c[n-1]=i;
                c[n]=j;
            }
    ll now=a[id[n]][c[n]];
    for(int i=n-1;i>=2;--i)
    {
        for(int j=0;j<3;++j)
            if(dp[i][j][c[i]]+now==ans&&j!=c[i+1])
        {
            c[i-1]=j;
        }
        now+=a[id[i]][c[i]];
    }
    for(int i=1;i<=n;++i) output[id[i]]=c[i];
    for(int i=1;i<=n;++i) printf("%d ",output[i]+1);
    return 0;
}
