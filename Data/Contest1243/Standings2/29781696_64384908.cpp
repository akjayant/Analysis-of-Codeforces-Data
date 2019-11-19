
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sz size()
#define cnt continue
#define fr(i, l, r) for(int i = l; i <= r; ++ i)
#define rf(i, r, l) for(int i = r; i >= l; -- i)

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <pii> vpi;
typedef vector <pll> vpl;

mt19937_64 rnd(time(NULL));

const ll I = 1e18 + 10;
const ll N = 2e6 + 10;
const ll M = 1e9 + 7;
const ll oo = 1e18;

ll a[N], mn[N], s[N], p[N], d[N], f[N], n, mx, l, r, ans;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    ll ans = n;
    for(ll i = 2; i * i <= n; ++ i){
        if(n % i == 0){
            ll x = i;
            ans = __gcd(ans, x);
            x = n / i;
            ans = __gcd(ans, x);
        }
    }
    cout << ans;
    return 0;
}

/*
4 2
1 2 10 11
*/
