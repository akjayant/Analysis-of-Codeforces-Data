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
 
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll MAXN = 1e5 + 10;
const ll MOD = 1e9 + 7;

ll dp[MAXN][3][3];
ll c;

ll rec(ll idx,ll prev1,ll prev2){
    if(idx == c+1) return 1;

    ll &ans = dp[idx][prev1][prev2];

    if(ans != -1) return ans;

    ans = 0;

    if(prev1 == prev2){
        FOR(cc,1,2){
            if(cc != prev1) ans = (ans + rec(idx+1,cc,prev1))%MOD; 
        }
    }else {
        FOR(i,1,2){
            ans = (ans + rec(idx+1,i,prev1))%MOD;
        }
    }

    return ans;
}

void solve(){
    ll n,m; cin>>n>>m;

    MINUS(dp);

    c = n;
    ll ans = rec(1,0,0);

    MINUS(dp);

    c = m;
    ll ans2 = rec(1,0,0);    

    ll anss = (ans + ans2 - 2)%MOD;
    anss = (anss + MOD)%MOD;

    cout<<anss<<endl;
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