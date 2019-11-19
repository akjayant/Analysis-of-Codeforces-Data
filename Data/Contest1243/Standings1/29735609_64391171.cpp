#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cerr << #x << " : " << x << endl;
const ll maxn=1e6+5;
set<ll> adj[maxn];
set<ll> unvis;
vector<ll> comp(maxn);
vector<ll> deg(maxn);
set<ll> c[maxn];
ll ctr=0;
void dfs(ll u){
    comp[u]=ctr;
    c[ctr].insert(u);
    vector<ll> tovisit;
    for(ll x:unvis){
        if(adj[u].count(x)==0){
            tovisit.push_back(x);
        }
    }
    for(ll x:tovisit){
        unvis.erase(x);
    }
    for(ll x:tovisit){
        dfs(x);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,m;
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(ll i=1;i<=n;i++){
        deg[i]=n-1-adj[i].size();
    }
    for(ll i=1;i<=n;i++){
        unvis.insert(i);
    }
    while(unvis.size()){
        ll cur=*unvis.begin();
        unvis.erase(unvis.begin());
        dfs(cur);ctr++;
    }
    cout << ctr-1 << endl;
    return 0;
}