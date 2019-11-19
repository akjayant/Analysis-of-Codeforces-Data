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
unordered_map<ll,ll> mapa;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,p,w,d; cin >> n >> p >> w >> d;
    ll pp = p;
    ll kek = p%w;
    ll y_ = -1;
    for(ll i = 0;i<w;i++){
        if((i*d)%w == kek){
            y_ = i;
            ll y = y_;
            p = pp - y*d;
            if(p < 0){
                continue;
            }
            else {
                ll x = p/w;
                if(x+y <= n){
                    cout << x << " " << y << " " << n-x-y << endl;
                    return 0;
                }
                else {
                    continue;
                }
            }
        }
    }

    cout << -1 ;
    return 0;
}
/*
1
19 12
19 18 15 14 12 11 10 8 7 5 4 3
*/