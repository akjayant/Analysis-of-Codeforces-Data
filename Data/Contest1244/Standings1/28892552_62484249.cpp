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
    ll n, k;  cin >> n >> k;
    vector<ll>a(n); for(ll i= 0 ;i<n;i++) cin >> a[i];
    for(ll x : a){mapa[x]++;};
    set<ll>kek; for(ll x : a) kek.insert(x);
    while(kek.size() > 1){
        ll x1 = *kek.begin();
        auto it = kek.begin(); it++;
        ll x2 = *it;
        it = kek.end(); it--;
        ll y2 = *it;
        it--;
        ll y1 = *it;

        ll cnt1 = mapa[x1];
        ll cnt2 = mapa[y2];
        if(cnt1 <= cnt2) {
            ll kk = (x2 - x1)*cnt1;
            if(k > kk){
                k-=kk;
                mapa[x2] += mapa[x1];
                mapa[x1] = 0;
                kek.erase(x1);
            } else {
                ll tr = k / cnt1;
                x2 = x1 + tr;
                kek.erase(x1);
                kek.insert(x2);
                break;
            }
        } else {
            ll kk = (y2 - y1)*cnt2;
            if(k > kk){
                k-=kk;
                mapa[y1] += mapa[y2];
                mapa[y2] = 0;
                kek.erase(y2);
            } else {
                ll tr = k / cnt2;
                y1 = y2 - tr;
                kek.erase(y2);
                kek.insert(y1);
                break;
            }
        }
    }
    auto it = kek.begin();
    ll x = *it;
    it = kek.end(); it--;
    ll y = *it;
    cout << y - x << endl;
    return 0;
}
/*
1
19 12
19 18 15 14 12 11 10 8 7 5 4 3
*/