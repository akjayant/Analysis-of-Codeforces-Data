#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll maxn=1e5+5;
ll e[2005][2005];
ll dist[2005];
ll cost[2005];
ll use[2005];
ll x[2005],y[2005];
ll from[2005];
int main(){
    ios::sync_with_stdio(0);
    ll t,i,t1,t2,t3,j,a,b,c,n;
    memset(dist,0x3f,sizeof(dist));
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for (i=1;i<=n;i++){
        cin>>t1;
        e[0][i]=e[i][0]=t1;
    }
    for (i=1;i<=n;i++)
        cin>>cost[i];
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++){
        if (i==j){
            e[i][j]=e[j][i]=0;
        }
        else {
            e[i][j]=e[j][i]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(cost[i]+cost[j]);
        }
    }
    dist[0]=0;
    memset(use,0,sizeof(use));
    ll ans=0;
    for (i=0;i<=n;i++){
        ll v=-1;
        for (j=0;j<=n;j++){
            if (!use[j]&&(v==-1||dist[v]>dist[j]))
                v=j;
        }
        if (v==-1)
            break;
        use[v]=1;
        ans+=dist[v];
        for (j=0;j<=n;j++)
        if (!use[j]&&dist[j]>e[j][v]){
            dist[j]=e[j][v];
            from[j]=v;
        }
    }
    cout<<ans<<'\n';
    vector<ll> vans;
    for (i=1;i<=n;i++)
        if (from[i]==0)
            vans.push_back(i);
    cout<<vans.size()<<'\n';
    for (i=0;i<vans.size();i++)
        cout<<vans[i]<<' ';
    cout<<'\n';
    cout<<n-vans.size()<<'\n';
    for (i=1;i<=n;i++)
        if(from[i]!=0)
        cout<<from[i]<<' '<<i<<'\n';

}
