#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define endl '\n'
#define ld long double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
#define FI(i,n) for (ll i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
#define sz(x) (ll)x.size()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
 
// I want to be the very best, like no one ever was, I will battle everyday to claim my rightful place
// Not gonna give up until it's over
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
// I am questioning life and universe and 
// everything else after looking at this

const ll MAXN = 1e5 + 10;
vector<ll> graph[MAXN];
ll color[3][MAXN];
bool flag = true;
ll dp[MAXN][4][4];
ll val[MAXN];
ll s = 0,x = 0;
ll anss[MAXN];

void dfs(ll u,ll p){
    val[++s] = u;
    for(ll v:graph[u]){
        if(v == p) continue;
        dfs(v,u);
    }
}

ll rec(ll idx,ll p1,ll p2){
    if(idx == s+1) return 0;

    ll &ans = dp[idx][p1][p2];

    if(ans != -1) return ans;

    ans = 1e15;

    FOR(co,1,3){
        if(p1 == co || p2 == co) continue;
        ans = min(ans,rec(idx+1,co,p1) + color[co-1][val[idx]]);
    } 

    return ans;
}

void backtrack(ll idx,ll p1,ll p2,ll ans){
    if(idx == s+1) return;

    FOR(co,1,3){
        if(p1 == co || p2 == co) continue;
        if(rec(idx+1,co,p1) + color[co-1][val[idx]] == ans){
            anss[val[idx]] = co;
            backtrack(idx+1,co,p1,ans - color[co-1][val[idx]]); 
        }
    }
}

void solve(){
    ll n; cin>>n;
    FOR(i,0,2) FOR(j,1,n) cin>>color[i][j];

    FOR(i,1,n-1){
        ll u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(n == 1){
        cout<<min({color[0][1],color[1][1],color[2][1]})<<endl;
        return;
    }

    FOR(i,1,n) if(graph[i].size() >= 3) flag = false;

    if(!flag){
        cout<<-1<<endl;
        return;
    }

    FOR(i,1,n) if(graph[i].size() == 1) x = i;
    dfs(x,0);

    MINUS(dp);
    ll ans = rec(1,0,0);
    cout<<ans<<endl;
    backtrack(1,0,0,ans);

    FOR(i,1,n) cout<<anss[i]<<" ";
}

signed main(){
 
   FastRead;    
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    t = 1; 
    // cin>>t;
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}