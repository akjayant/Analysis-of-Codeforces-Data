#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , ll >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
const int N=1e5+100;
vector <int> g[N];
vector <int> c;
ll val[N][3];
ll ans1[N];
ll dfs(ll v,ll p){
    c.pb(v);
    for (int i=0;i<g[v].size();i++){
        ll u=g[v][i];
        if (u==p){
            continue;
        }

        dfs(u,v);

    }


}
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int j=0;j<3;j++){
        for (int i=1;i<=n;i++){
            cin >> val[i][j];
        }
    }
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i=1;i<=n;i++){
        if (g[i].size()>2){
            cout << -1;
            return 0;
        }
    }
    for (int i=1;i<=n;i++){
        if (g[i].size()==1){
            dfs(i,i);
            break;
        }
    }
   // cout << c[1] << endl;
    /// 0 1 2
    ll ans=0;
    ll ma=1e15;
    ll x,y,z;
    for (int i=1;i<=n;i++){
        if (i%3==0){
            ans+=val[c[i-1]][2];
        }
        if (i%3==1){
            ans+=val[c[i-1]][0];
        }
        if (i%3==2){
            ans+=val[c[i-1]][1];
        }
    }
    if (ans<ma){
        x=2;
        y=0;
        z=1;
    }
    ma=min(ma,ans);
    ans=0;

    for (int i=1;i<=n;i++){
        if (i%3==0){
            ans+=val[c[i-1]][2];
        }
        if (i%3==1){
            ans+=val[c[i-1]][1];
        }
        if (i%3==2){
            ans+=val[c[i-1]][0];
        }
    }
    if (ans<ma){
        x=2;
        y=1;
        z=0;
    }
    ma=min(ma,ans);
    ans=0;
    for (int i=1;i<=n;i++){
        if (i%3==0){
            ans+=val[c[i-1]][1];
        }
        if (i%3==1){
            ans+=val[c[i-1]][2];
        }
        if (i%3==2){
            ans+=val[c[i-1]][0];
        }
    }
    if (ans<ma){
        x=1;
        y=2;
        z=0;
    }
    ma=min(ma,ans);
    ans=0;
    for (int i=1;i<=n;i++){
        if (i%3==0){
            ans+=val[c[i-1]][1];
        }
        if (i%3==1){
            ans+=val[c[i-1]][0];
        }
        if (i%3==2){
            ans+=val[c[i-1]][2];
        }
    }
    if (ans<ma){
        x=1;
        y=0;
        z=2;
    }
    ma=min(ma,ans);
    ans=0;
    for (int i=1;i<=n;i++){
        if (i%3==0){
            ans+=val[c[i-1]][0];
        }
        if (i%3==1){
            ans+=val[c[i-1]][1];
        }
        if (i%3==2){
            ans+=val[c[i-1]][2];
        }
    }
    if (ans<ma){
        x=0;
        y=1;
        z=2;
    }
    ma=min(ma,ans);
    ans=0;
    for (int i=1;i<=n;i++){
        if (i%3==0){
            ans+=val[c[i-1]][0];
        }
        if (i%3==1){
            ans+=val[c[i-1]][2];
        }
        if (i%3==2){
            ans+=val[c[i-1]][1];
        }
    }
    if (ans<ma){
        x=0;
        y=2;
        z=1;
    }
    ma=min(ma,ans);
    ans=0;
    cout << ma << endl;
    for (int i=1;i<=n;i++){
        if (i%3==0){
            ans1[c[i-1]]=x+1;
            //cout << x+1 << " ";
        }
        if (i%3==1){
            ans1[c[i-1]]=y+1;
            //cout << y+1 << " ";
        }
        if (i%3==2){
            ans1[c[i-1]]=z+1;
            //cout << z+1 << " ";
        }
    }
    for (int i=1;i<=n;i++){
        cout << ans1[i] << " ";
    }
    //cout << min(dp[1][0],min(dp[1][2],dp[1][1]));

}



















