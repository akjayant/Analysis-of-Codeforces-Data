#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+23;

int n;
vector<int> g[maxn];
int c[3][maxn];
int a[maxn];
int b[12],cnt[3];
ll pre[3][maxn];
void dfs(int p,int fa,int a1,int a2)
{
    a[p]=6-a1-a2;
    for(int i:g[p]){
        if(i==fa) continue;
        dfs(i,p,a[p],a1);
    }
}

ll check(int a1,int a2,int a3)
{
    b[1]=a1-1,b[2]=a2-1,b[3]=a3-1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=c[b[a[i]]][i];
    }
    return ans;
}

int main()
{
    int u,v;
    cin >> n ;
    for(int i=0;i<3;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&c[i][j]);
            pre[i][j]=pre[i][j-1]+c[i][j];
        }
    }
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int mx=0;
    for(int i=1;i<=n;i++) mx=max(mx,(int)g[i].size());
    if(mx>2) return 0*printf("-1");
    int pos=-1;
    for(int i=1;i<=n;i++){
        if(g[i].size()==2){
            pos=i;break;
        }
    }
    if(pos!=-1){
        a[pos]=2;
        dfs(g[pos][0],pos,2,3);
        dfs(g[pos][1],pos,2,1);
    }
    else{
        a[1]=1,a[2]=2;
    }
    for(int i=1;i<=n;i++) cnt[a[i]-1]++;
    //for(int i=0;i<3;i++) printf("%d %d\n",i,cnt[i]);
    ll ans=1e18;int p[4];
    if(ans>check(1,2,3)) ans=min(ans,check(1,2,3)),p[1]=1,p[2]=2,p[3]=3;
    if(ans>check(1,3,2)) ans=min(ans,check(1,3,2)),p[1]=1,p[2]=3,p[3]=2;
    if(ans>check(2,1,3)) ans=min(ans,check(2,1,3)),p[1]=2,p[2]=1,p[3]=3;
    if(ans>check(2,3,1)) ans=min(ans,check(2,3,1)),p[1]=2,p[2]=3,p[3]=1;
    if(ans>check(3,1,2)) ans=min(ans,check(3,1,2)),p[1]=3,p[2]=1,p[3]=2;
    if(ans>check(3,2,1)) ans=min(ans,check(3,2,1)),p[1]=3,p[2]=2,p[3]=1;
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",p[a[i]]);
}
