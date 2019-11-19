#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long
#define pb push_back
#define pLL pair<LL,LL>
#define ff first
#define ss second
#define rep(i,a,b) for(LL i=a;i<=b;++i)
#define repb(i,a,b) for(LL i=a;i>=b;--i)
#define ld double
#define mp make_pair
#define vLL vector<LL>
#define vpLL vector<pLL>
#define vld vector<ld>
#define pld pair<ld,ld>
#define vpld vector<pld>
#define SLL set<LL>
#define SpLL set<pLL>
#define FIO ios::sync_with_stdio(false)
#define inf 1e17

LL n, adj[2005][2005], c[2005], k[2005], dis[2005], par[2005], vis[2005];
pLL loc[2005];

priority_queue< pLL,vpLL,greater<pLL> > pq;
vpLL edges;
vLL stations;

LL prims()
{
    rep(i,1,n) dis[i]=c[i];
    rep(i,1,n) par[i]=i;
    rep(i,1,n) pq.push(mp(c[i], i));
    LL ans=0;
    edges.clear();
    stations.clear();
    do{
        pLL v=pq.top();pq.pop();
        if(vis[v.ss]) continue;
        vis[v.ss] = 1;
        if(par[v.ss] != v.ss) {
            edges.pb(mp(par[v.ss], v.ss));
            ans += v.ff;
        }
        else {
            stations.pb(v.ss);
            ans += c[v.ss];   
        }
        rep(i,1,n){
            if(vis[i]) continue;
            if(dis[i] > adj[v.ss][i]){
                dis[i] = adj[v.ss][i];
                par[i] = v.ss;
                pq.push(mp(dis[i], i));
            }
        }
    }while(!pq.empty());
    return ans;
}

int main() {
    cin >> n;
    rep(i,1,n) cin >> loc[i].ff >> loc[i].ss;
    rep(i,1,n) cin >> c[i];
    rep(i,1,n) cin >> k[i];
    rep(i,1,n) adj[i][i] = inf;
    rep(i,1,n) rep(j, i+1, n) {
        adj[i][j] = (k[i]+k[j])*(abs(loc[i].ff-loc[j].ff) + abs(loc[i].ss-loc[j].ss));
        adj[j][i] = adj[i][j];
    }
    cout << prims() << "\n";
    if(!stations.empty()) {
        cout << stations.size() << "\n";
        for(auto x: stations) cout << x << " ";
        cout << "\n";
    }
    else cout << "0\n";
    if(!edges.empty()) {
        cout << "\n" << edges.size() << "\n";
        for(auto x: edges) {
            cout << x.ff << " " << x.ss << "\n";
        }
    }
    else cout << "0\n";
}