#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int kk,tot,fa[2005],n;
ll a[2005],b[2005],c[2005],k[2005];
bool vis[2005];
bool v[5000005];
ll ans;
struct t{
    int x,y;
    ll w;
}d[5000005];
bool cmp(t x,t y){
    return x.w<y.w;
}
int getf(int x){
    if (fa[x]==x)return x;
    fa[x]=getf(fa[x]);
    return fa[x];
}
void merge(int x,int y,ll z,int t){
    int xx,yy;
    xx=x;yy=y;
    x=getf(x);
    y=getf(y);
    if (y!=x){
      //  printf("%d %d %lld\n",x,y,z);
      //  printf("%d %d\n",x,y);
        kk++;
        fa[y]=x;
        if (xx==0)vis[yy]=1;
        else if (yy==0)vis[xx]=1;
        else v[t]=1;
        ans=ans+z;
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%lld%lld",&a[i],&b[i]);
    for (int i=1;i<=n;i++)scanf("%lld",&c[i]);
    for (int i=1;i<=n;i++)scanf("%lld",&k[i]);
    tot=0;
    for (int i=1;i<=n;i++){
        tot++;
        d[tot].x=0;d[tot].y=i;d[tot].w=c[i];
    }
    for (int i=1;i<=n-1;i++)
        for (int j=i+1;j<=n;j++){
            tot++;d[tot].x=i;d[tot].y=j;d[tot].w=(abs(a[i]-a[j])+abs(b[i]-b[j]))*(k[i]+k[j]);
        }
    for (int i=0;i<=n;i++)fa[i]=i;
    sort(d+1,d+1+tot,cmp);
    kk=0;
    memset(vis,0,sizeof(vis));
    memset(v,0,sizeof(v));
    for (int i=1;i<=tot;i++){
        merge(d[i].x,d[i].y,d[i].w,i);
        if (kk==n)break;
    }
    printf("%lld\n",ans);
    ans=0;
    for (int i=1;i<=n;i++)
        if (vis[i])ans++;
    printf("%lld\n",ans);
    for (int i=1;i<=n;i++)
        if (vis[i])printf("%d ",i);
    ans=0;
    printf("\n");
    for (int i=1;i<=tot;i++)
        if (v[i])ans++;
    printf("%lld\n",ans);
    for (int i=1;i<=tot;i++)
        if (v[i])printf("%d %d\n",d[i].x,d[i].y);
    return 0;
}