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

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t; while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        ll kek = 0;
        for(char c : s) if(c == '1'){
            kek++;
        }
        ll ans = n+kek;
        ll fst = -1;
        ll lst = -1;
        for(ll i =0 ;i<n;i++){
            if(s[i] == '1') lst = i;
        }
        for(ll i =n-1 ;i>=0;i--){
            if(s[i] == '1') fst = i;
        }
        if(fst != -1){
            ans = max(ans, 2*(lst+1));
            ans = max(ans, 2*(n-fst));
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
1
19 12
19 18 15 14 12 11 10 8 7 5 4 3
*/