#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int >
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define LL long long
using namespace std;
const int INF=0x3f3f3f3f,N=2e6+5,MOD=1e9+7;

int n,x[N],y[N],c[N],k[N],vis[N],pre[N];
LL a[2005][2005],dis[N],res;
vi up;
vector<pii>dn;
void prim(){
    for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f3f3f3f3fLL;
    dis[n]=0;
    while(1){
        LL Min=0x3f3f3f3f3f3f3f3fLL,k=-1;
        for(int i=1;i<=n;i++)if(!vis[i]&&Min>dis[i])Min=dis[i],k=i;
        if(k==-1)return;
        vis[k]=1;res+=Min;
        if(k!=n){
            if(pre[k]==n)up.pb(k); else dn.pb(mp(pre[k],k));
        }
        for(int i=1;i<=n;i++)if(i!=k){
            if(!vis[i]&&dis[i]>a[k][i])dis[i]=a[k][i],pre[i]=k;
        }
    }
}
int Solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cin>>k[i];
    n++;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++)if(i!=j){
            a[i][j]=1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
        }
    }
    for(int i=1;i<n;i++)a[i][n]=a[n][i]=c[i];
    prim();
    cout<<res<<endl;
    cout<<up.size()<<endl;
    for(auto p:up)cout<<p<<" ";cout<<endl;
    cout<<dn.size()<<endl;
    for(auto p:dn)cout<<p.fi<<" "<<p.se<<endl;
    return 0;
}
void Pre(){
}
int main() {
#ifndef ONLINE_JUDGE
 freopen("in.txt","r",stdin);
//  freopen("o1.txt","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    Pre();
    while(Solve());
    return 0;
}

