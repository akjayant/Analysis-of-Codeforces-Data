#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned ll
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair<ll, ll>
#define mt make_tuple
#define mn(a, b) a = min(a, b)
#define mx(a, b) a = max(a, b)
 
using namespace std;
 
const ll INF = (ll)2e9;
const ll inf = (ll)2e18;
const ld eps = (ld)1e-6;
const ll mod = (ll)1e9 + 7;
const ll MAXN = (ll)1e6;
const ll MAXC = (ll)6e6;
const ll MAXLOG = 65;
const ll maxlen = (ll)1e5;
const ll asci = (ll)256;
const ll block = 707;
//
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;*/
 
template <class T>
istream& operator >>(istream &in, vector<T> &arr){
     for (T &cnt : arr) {
        in >> cnt;
    }
    return in;
};

vi graph[MAXN];
int cnt = 1;

void dfs(int v, int p, vi &b) {
    if (graph[v].size() - 1 > 1) cout << -1, exit(0);
    for (int u : graph[v]) {
        if (p == u) continue;
        b[cnt] = u;
        cnt++;
        dfs(u, v, b);
    }
}
 
void solve() {
    int n; cin >> n;
    vvi c(3, vi(n));
    vi bamboo(n);
    cin >> c[0] >> c[1] >> c[2];
    for (int i = 0; i < n - 1; ++i) {
        int v, u; 
        cin >> v >> u;
        v--, u--;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    int list = -1;
    for (int i = 0; i < n; ++i) {
        if (graph[i].size() == 1) list = i;
    }
    vi color(n);
    bamboo[0] = list;
    dfs(list, -1, bamboo);
    ll bi, bj, ans = inf;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            color[0] = i, color[1] = j;
            for (int k = 2; k < n; ++k) color[k] = 3 - color[k - 1] - color[k - 2];
            ll new_ans = 0;
            for (int k = 0; k < n; ++k) {
                new_ans += c[color[k]][bamboo[k]];
            }
            if (ans > new_ans) {
                ans = new_ans;
                bi = i;
                bj = j;
            }
        }
    }
    color[0] = bi, color[1] = bj;
    vi a(n);
    for (int i = 2; i < n; ++i) {
        color[i] = 3 - color[i - 1] - color[i - 2];
        a[bamboo[i]] = color[i];
    }
    for (int i = 0; i < n; ++i) {
        a[bamboo[i]] = color[i];
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] + 1 << " ";
    }
}
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    cout.precision(30);
    solve();
 
    return 0;
}