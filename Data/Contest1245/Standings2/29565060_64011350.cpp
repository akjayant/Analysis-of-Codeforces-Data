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

#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
#pragma loop_opt(on)
#ifdef local
#define debug(x) (cerr<<#x<<" = "<<(x)<<'\n')
#else
#define debug(x) ((void)0)
#endif // local
#define all(v) begin(v),end(v)
#define siz(v) (ll(v.size()))
#define get_pos(v,x) (lower_bound(all(v),x)-begin(v))
#define sort_uni(v) sort(begin(v),end(v)),v.erase(unique(begin(v),end(v)),end(v))
#define pb emplace_back
#define ff first
#define ss second
#define mid (l+(r-l>>1))
#define mem(v,x) memset(v,x,sizeof v)

using namespace std;
using namespace __gnu_pbds;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
template <typename T> using max_heap = __gnu_pbds::priority_queue<T,less<T> >;
template <typename T> using min_heap = __gnu_pbds::priority_queue<T,greater<T> >;
template <typename T> using rbt = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr ld PI = acos(-1), eps = 1e-9;
constexpr ll N = 2025, INF = 1e18, MOD = 1000000007, K = 5;
constexpr ll modpow(ll e,ll p,ll m=MOD) {ll r=1; for(;p;p>>=1,e=e*e%m) if(p&1) r=r*e%m; return r;}
constexpr inline ll cdiv(ll x, ll m) { return (x+m-1)/m; } // ceiling divide, x/m for flooring divide
template <typename T> void M(T &x, ll m=MOD){x%=m; if(x<0) x+=m;}

ll g[N][N],n;
ll x[N],y[N],c[N],k[N],tot,A[N*N],ta;
pair<ll,pll> E[N*N];
void addE(int a,int b,ll w) {
    E[tot++] = {w,{a,b}};
}
int pa[N],rk[N];
int anc(int x){return x==pa[x]?x:(pa[x]=anc(pa[x]));}
bool uni(int x,int y) {
    if((x=anc(x)) == (y=anc(y))) return false;
    if(rk[x] < rk[y]) swap(x,y);
    return pa[y] = x, rk[x]!=rk[y]||++rk[x];
}
ll sv() {
    sort(E,E+tot);
    ll ans=0;
    for(int i = 0; i < tot; i++) if(uni(E[i].ss.ff,E[i].ss.ss)) ans+=E[i].ff, A[ta++] = i;
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i <= n; i++) pa[i]=i;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> k[i];
    for(int i = 1; i <= n; i++) addE(0,i,c[i]);
    for(int i = 1; i <= n; i++) for(int j = 1; j < i; j++) addE(i,j,(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])));
    cout << sv() << '\n';
    vector<int> vv;
    vector<pll> ed;
    for(int k = 0; k < ta; k++) {
        int id = A[k];
        int a = E[id].ss.ff, b = E[id].ss.ss;
        if(a==0 || b==0) vv.pb(a|b);
        else ed.pb(a,b);
    }
    cout << vv.size() << '\n';
    for(int x:vv) cout << x << ' '; cout << '\n';
    cout << ed.size() << '\n';
    for(pll p:ed) cout << p.ff << ' ' << p.ss << '\n';
}
