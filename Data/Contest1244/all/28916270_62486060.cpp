//   __________________
//  | ________________ |
//  ||          ____  ||
//  ||   /\    |      ||
//  ||  /__\   |      ||
//  || /    \  |____  ||
//  ||________________||
//  |__________________|
//  \###################\
//   \###################\
//    \        ____       \
//     \_______\___\_______\
// An AC a day keeps the doctor away.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast")
//#pragma loop_opt(on)
#ifdef local
#define debug(x) (cerr<<#x<<" = "<<(x)<<'\n')
#else
#define debug(x) ((void)0)
#endif // local
#define all(v) begin(v),end(v)
#define siz(v) (ll(v.size()))
#define get_pos(v,x) (lower_bound(all(v),x)-begin(v))
#define pb emplace_back
#define ff first
#define ss second
#define mid (l+(r-l>>1))
#define mem(v,x) memset(v,x,sizeof v)
#define int ll

using namespace std;
using namespace __gnu_pbds;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
template <typename T> using rkt = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr ld PI = acos(-1), eps = 1e-9;
constexpr ll N = 100025, INF = 1e18, MOD = 1000000007, K = 20;
constexpr inline ll cdiv(ll x, ll m) { return (x+m-1)/m; } // ceiling divide, x/m for flooring divide
template <typename T> void M(T &x, ll m = MOD){x%=m; if(x<0) x+=m;}

ll n,cost[3][N],pa[N],dp[3][N], fr[3][N];
vector<ll> g[N],v;
int ans[N],res[N];
void dfs(int i) {
    v.pb(i);
    for(auto j:g[i]) if(j != pa[i]) {
        pa[j] = i;
        dfs(j);
    }
}
signed main() {
    mem(dp,0x3f);
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int c = 0; c < 3; c++) for(int i = 1; i <= n; i++) cin >> cost[c][i];
    for(int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        g[a].pb(b), g[b].pb(a);
    }
    for(int i = 1; i <= n; i++) if(g[i].size() >= 3) return cout << -1 << '\n', 0;
    for(int i = 1; i <= n; i++) if(g[i].size() == 1) {
        dfs(i);
        break;
    }
    ll ret = INF;
    for(int s = 0; s < 9; s++) {
        ans[0] = s%3, ans[1] = s/3;
        if(ans[0]==ans[1]) continue;
        for(int i = 2; i < n; i++) ans[i]=3^ans[i-1]^ans[i-2];
        ll c = 0;
        for(int i = 0; i < n; i++) c+=cost[ans[i]][v[i]];
        debug(c);
        debug(ans[0]),debug(ans[1]);
        if(c < ret) {
            ret = c;
            for(int i = 0; i < n; i++) res[v[i]]=ans[i];
        }
    }
    cout << ret << '\n';
    for(int i = 1; i <= n; i++) cout << res[i]+1 << ' ';
}
