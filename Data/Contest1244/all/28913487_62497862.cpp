#include<bits/stdc++.h>
using namespace std;
const int M=100010;
int n,a[M][5],d[6][3]={1,2,3,1,3,2,2,1,3,2,3,1,3,1,2,3,2,1};
int ro[M],color[M],vis[M];
typedef long long ll;
vector<int> vc[M];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=3;++i)for(int j=1;j<=n;++j)scanf("%d",&a[j][i]);
    int x,y,f=0,st=-1;
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        ro[x]++;ro[y]++;
        if(x>y)swap(x,y);
        vc[x].push_back(y);
        vc[y].push_back(x);
        if(ro[x]>2||ro[y]>2)f=1;
    }
    for(int i=1;i<=n;++i)if(ro[i]==1)st=i;
    if(f)printf("-1");
    else{
        ll ans=1ll<<60;
        for(int i=0;i<6;++i){
            memset(vis,0,sizeof vis);
            vis[st]=1;
            ll t=0,tmp=0,now=st;
            while(now){
                tmp+=a[now][d[i][t%3]];
                int ff=0;
                for(auto v:vc[now]){
                    if(vis[v]==0){
                        vis[v]=1;
                        now=v;
                        ff=1;
                    }
                }
                if(ff==0)break;
                t++;
            }
            ans=min(ans,tmp);
            if(ans==tmp)f=i;
        }
        printf("%lld\n",ans);
        int t=0;
        memset(vis,0,sizeof vis);
        vis[st]=1;
        while(st){
            color[st]=d[f][t%3];
            t++;
            int ff=0;
            for(auto v:vc[st]){
                if(vis[v]==0){
                    vis[v]=1;
                    st=v;
                    ff=1;
                }
            }
            if(ff==0)break;
        }
        for(int i=1;i<=n;++i)printf("%d ",color[i]);
    }
}
