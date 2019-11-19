#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int maxn=2010;
const int maxm=4010010;
struct E1
{
    int u,v;
    ll w;
    bool operator<(const E1&P)const{
        return w<P.w;
    }
}E[maxm];
int fa[maxn],x[maxn],y[maxn],c[maxn],k[maxn],V[maxn];
pii use[maxm];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
    #ifdef local
    freopen("a.in","r",stdin);
    #endif // local
    int n,u,v;
    while(~scanf("%d",&n)){
        ll ans=0;
        int m=0,top=0,vtop=0;
        for(int i=0;i<=n;++i) fa[i]=i;
        for(int i=1;i<=n;++i) scanf("%d%d",x+i,y+i);
        for(int i=1;i<=n;++i) scanf("%d",c+i),E[m++]={0,i,c[i]};
        for(int i=1;i<=n;++i) scanf("%d",k+i);
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                E[m++]={i,j,(ll)(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))};
            }
        }
        sort(E,E+m);
        for(int i=0;i<m;++i){
            int fx=find(u=E[i].u),fy=find(v=E[i].v);
            if(fx==fy) continue;
            fa[fx]=fy;
            ans+=E[i].w;
            if(u>v) swap(u,v);
            if(u==0) V[vtop++]=v;
            else use[top++]=make_pair(E[i].u,E[i].v);
        }
        printf("%lld\n%d\n",ans,vtop);
        for(int i=0;i<vtop;++i) printf("%d%c",V[i]," \n"[i==vtop-1]);
        printf("%d\n",top);
        for(int i=0;i<top;++i) printf("%d %d\n",use[i].first,use[i].second);
    }
    return 0;
}
