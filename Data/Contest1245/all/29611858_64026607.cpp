#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
const int MAXN = 1e4+5;
const int MAXM = 5e6+5;
const int MOD = 1e9+7;
struct rec{int x,y;ll z;}edge[MAXM];
int pre[MAXN],a[MAXN],b[MAXN],x[MAXN],y[MAXN],n;
bool operator <(rec a,rec b){
    return a.z<b.z;
}
int Find(int x){
    return pre[x]==x?x:pre[x]=Find(pre[x]);
}
vector<int>p;
vector<pair<int,int> >q;
int main()
{
    while(~scanf("%d",&n)){
        p.clear();
        q.clear();
        rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,n)scanf("%d",&b[i]);
        int tot=0;
        rep(i,1,n){
            rep(j,1,n){
                if(i==j)continue;
                edge[++tot].x=i;
                edge[tot].y=j;
                edge[tot].z=((ll)b[i]+b[j])*((ll)abs(x[i]-x[j])+abs(y[i]-y[j]));
            }
        }
        rep(i,1,n){
            edge[++tot].x=i;
            edge[tot].y=n+1;
            edge[tot].z=a[i];
        }
        sort(edge+1,edge+tot+1);
        rep(i,1,n+1)pre[i]=i;
        ll ans=0;
        rep(i,1,tot){
            int x=Find(edge[i].x);
            int y=Find(edge[i].y);
            if(x==y)continue;
            pre[x]=y;
            ans+=edge[i].z;
            if(edge[i].y==n+1)p.push_back(edge[i].x);
            else q.push_back({edge[i].x,edge[i].y});
        }
        printf("%I64d\n",ans);
        int len=p.size();
        printf("%d\n",len);
        rep(i,0,len-1){
            printf("%d ",p[i]);
        }puts("");
        len=q.size();
        printf("%d\n",len);
        rep(i,0,len-1){
            printf("%d %d\n",q[i].first,q[i].second);
        }
    }

    return 0;
}
