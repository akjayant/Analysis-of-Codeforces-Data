//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")
           
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
           
using namespace std;
using namespace __gnu_pbds;
           
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
           
using matrix = vector<vector<ll>>;
template<typename T>
using kawaii_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
           
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//#define int long long;
           
void FAST_IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.setf(ios::fixed);
    //cout.precision(20);
    #ifndef _offline
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
}

const ll INF = 1e18;
const int MAXN = 2020;
ll x[MAXN], y[MAXN], c[MAXN], k[MAXN], d[MAXN];
int par[MAXN];
bool used[MAXN];

signed main() {
    FAST_IO();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    fill(d, d + n, INF);
    fill(par, par + n, -1);
    vector<int> a;
    vector<pii> b;
    ll ans = 0;
    for (int iter = 0; iter < n; ++iter) {
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }
            if (pos == -1 || min(c[i], d[i]) < min(c[pos], d[pos])) {
                pos = i;
            }
        }
        if (c[pos] < d[pos]) {
            ans += c[pos];
            a.push_back(pos);
        }
        else {
            ans += d[pos];
            b.push_back({par[pos], pos});
        }
        used[pos] = true;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }
            ll val = (llabs(x[i] - x[pos]) + llabs(y[i] - y[pos])) * (k[i] + k[pos]);
            if (val < d[i]) {
                d[i] = val;
                par[i] = pos;
            }
        }
    }
    cout << ans << '\n';
    cout << a.size() << '\n';
    for (int i : a) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
    cout << b.size() << '\n';
    for (auto &[i, j] : b) {
        cout << i + 1 << ' ' << j + 1 << '\n';
    }
}  
