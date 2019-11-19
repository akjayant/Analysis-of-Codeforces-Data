#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <algorithm>
#define rep(i,x,y) for (int i=x; i<=(y); ++i)

using namespace std;
typedef long long ll;

const int N=1e5+10;
int n,w[3][N],c[N];
vector<int> adj[N];

ll dfs(int i,int j,int x,int fa)
{
    int k=3-i-j;
    ll s=w[j][x];
    for (auto v:adj[x])
        if (v!=fa)
            s+=dfs(j,k,v,x);
    return s;
}

void pnt(int i,int j,int x,int fa)
{
    int k=3-i-j;
    c[x]=j;
    for (auto v:adj[x])
        if (v!=fa)
            pnt(j,k,v,x);
}

int main()
{
    scanf("%d",&n);
    rep(i,0,2)
        rep(j,1,n)
            scanf("%d",w[i]+j);
    rep(i,2,n)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i,1,n)
        if ((int)adj[i].size()>2)
        {
            puts("-1");
            return 0;
        }
    int x=1;
    for (; (int)adj[x].size()!=1; ++x);
    int y=adj[x][0];
    ll ans=1ll<<62;
    rep(i,0,2)
        rep(j,0,2)
            if (i!=j)
            {
                ll k=dfs(i,j,y,x)+w[i][x];
                if (k<ans)
                    ans=k,c[x]=i,c[y]=j;
            }
    printf("%lld\n",ans);
    pnt(c[x],c[y],y,x);
    rep(i,1,n)
        printf("%d ",c[i]+1);
    return 0;
}
