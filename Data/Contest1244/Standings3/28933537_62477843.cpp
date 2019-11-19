#include <bits/stdc++.h>


//#define _FORTIFY_SOURCE 0
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#define ull unsigned long long
#define pll pair<ll, ll>
#define mp make_pair
#define ll long long
#define ld long double
#define i128 ll
#define pb push_back
#define deb(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define vi vector<ll>
typedef std::complex<ld> cmpl;


const ll mod = 1e9 + 7;
const ll P = 239;
const ll inf = (ll)1e18;
const long double MATH_E = 2.718281828459;
const long double eps = 1e-9;
const long double MATH_PI = atan2l(0, -1);


using namespace std;


template <class T>
istream& operator>>(istream &in, vector<T> &arr) {
    for (T &cnt : arr) {
        in >> cnt;
    }
    return in;
};


void solve() {
    vector<ll> colours = {0, 1, 2};
    ll n;
    cin >> n;
    vector<vector<ll>> cost(3, vector<ll>(n));
    cin >> cost;
    vector<vector<ll>> g(n);
    for (int i = 0; i < n - 1; i++) {
        ll v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].pb(u);
        g[u].pb(v);
    }
    int leaf = -1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() > 2) {
            cout << -1;
            return;
        }
        if (g[i].size() == 1) {
            leaf = i;
        }
    }
    vector<ll> cnt_c(n);
    vector<ll> ans(n);
    ll min_ans = inf;


    function<ll(ll, ll, ll)> dfs = [&](ll v, ll pr, ll colour) {
        ll res = 0;
        for (ll u : g[v]) {
            if (u != pr) {
                res += dfs(u, v, (colour + 1) % 3);
            }
        }
        res += cost[colours[colour]][v];
        cnt_c[v] = colours[colour];
        return res;
    };

    while (true) {
        ll kek = dfs(leaf, -1, 0);
        if (kek < min_ans) {
            min_ans = kek;
            ans = cnt_c;
        }
        if (!next_permutation(all(colours))) {
            break;
        }
    }
    cout << min_ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout.precision(30);
    srand(time(0));
    cout.setf(ios::fixed);
    solve();
    return 0;
}