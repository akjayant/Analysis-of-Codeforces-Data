#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define debug(x) cout<<#x<<" is "<<x<<endl;
const int maxn=1e6+5;
const ll mod=1e9+7;

struct edge{
    int fr;
    int to;
    ll val;
    bool operator<(const struct edge &aa)const {
        return val>aa.val;
    }
};

ll x[maxn],y[maxn],z[maxn],q[maxn];
int ac1[maxn],ac2[maxn],fa[maxn];
bool vis[maxn];

int finds(int x){
    int xx=x;
    while(fa[x]!=x)x=fa[x];
    while(fa[xx]!=x){
        int t=fa[xx];
        fa[xx]=x;
        xx=t;
    }
    return x;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)fa[i]=i;
    int tot=0;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    priority_queue<struct edge>pq;
    for(int i=1;i<=n;i++){
        scanf("%lld",&z[i]);
        pq.push({i,i,z[i]});
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&q[i]);
     //   pq.push({i,i,z[i]});
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            pq.push({i,j,(abs(x[i]-x[j])+abs(y[i]-y[j]))*(q[i]+q[j])});
        }
    }
    int w=0;
    ll ans=0;
    int w1,w2;
    w1=w2=0;
    while((!pq.empty())){
        struct edge aa=pq.top();
        pq.pop();
        int f1=finds(aa.fr);
        int f2=finds(aa.to);
        if(vis[f1]&&vis[f2])continue;
        //if(f1==f2)continue;
        if(aa.fr==aa.to){
            ac1[++w1]=aa.fr;
            ans+=aa.val;
            vis[f1]=1;
        }
        else if(f1!=f2){
            if(vis[f1]){
                fa[f2]=f1;
                ac2[++w2]=aa.fr;
                ac2[++w2]=aa.to;
                ans+=aa.val;
            }
            else{
                fa[f1]=f2;
                ac2[++w2]=aa.fr;
                ac2[++w2]=aa.to;
                ans+=aa.val;
            }
            //vis[f1]=vis[f2]=1;
        }
    }
    printf("%lld\n",ans);
    printf("%d\n",w1);
    for(int i=1;i<=w1;i++){
        printf("%d",ac1[i]);
        char cc=(i==w1)?'\n':' ';
        printf("%c",cc);
    }
    printf("%d\n",w2/2);
    for(int i=1;i<=w2;i+=2){
        printf("%d %d\n",ac2[i],ac2[i+1]);
     //   char cc=(i==w1)?'\n':' ';
       // printf("%c",cc);
    }
    return 0;
}
