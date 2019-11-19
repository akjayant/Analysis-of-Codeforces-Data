#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define all(x) x.begin(), x.end()
#define mp make_pair
#define X first
#define Y second

template<typename T>
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 gen(322);

ll const mod = 1e9 + 7;

namespace {
    ll mul(ll a, ll b) {
        ll val = a * b - (ll)((ld)a * b / mod) * mod;
        if (val < 0) val += mod;
        if (val >= mod) val -= mod;
        return val;
    }
    ll poww(ll a, ll b) {
        ll val = 1;
        a %= mod;
        while (b > 0) {
            if (b % 2) val = mul(a, val);
            a = mul(a, a);
            b >>= 1;
        }
        return val % mod;
    }
    ll inv(ll a) {
        return poww(a, mod - 2);
    }
}

ll const maxn = 3e5 + 5;
ll c[maxn][3];
vector<ll>g[maxn];
bool used[maxn];
ll d[maxn];

void dfs(ll u ,ll h){
    used[u] = 1;
    d[u] = h;
    for(ll v : g[u]){
        if(used[v]) continue;
        dfs(v, h+1);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for(ll j = 0;j <3;j++){
        for(ll i = 0;i<n;i++)
            cin >> c[i][j];
    }
    for(ll i = 0;i<n-1;i++){
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);g[b].push_back(a);
    }
    ll root = -1;
    for(ll x = 0; x < n;x++){
        if(g[x].size() == 1) root = x;
        if(g[x].size() > 2 ){
            cout << -1;
            return 0;
        }
    }
    dfs(root, 0);
    ll ans = LLONG_MAX;
    assert(root!=-1);
    ll aaa = -1, bbb = -1, ccc = -1;
    for(ll a =0 ;a < 3; a++){
        for(ll b = 0;b<3;b++){
            if(a == b) continue;
            ll u = root;
            set<ll>kek = {0,1,2};
            kek.erase(a); kek.erase(b);
            ll cc = *kek.begin();
            ll ans1=  0;
            for(ll v = 0;v<n;v++){
                if(d[v]%3 == 0){
                    ans1+=c[v][a];
                } else if(d[v]%3 == 1){
                    ans1+=c[v][b];
                } else ans1+=c[v][cc];
            }
            if(ans1 < ans){
                aaa = a;
                bbb = b; ccc = cc;
                ans = ans1;
            }
        }
    }
    cout << ans << endl;
    for(ll v = 0;v<n;v++){
        if(d[v]%3 == 0){
            cout << aaa+1 << " ";
        } else if(d[v]%3 == 1){
            cout << bbb+1 << " ";
        } else cout << ccc+1 << " ";
    }
    return 0;
}
/*
1
19 12
19 18 15 14 12 11 10 8 7 5 4 3
*/