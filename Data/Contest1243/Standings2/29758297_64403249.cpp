#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse4")
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <math.h>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long  double ld;
mt19937 rnd(random_device {}());
#define all(a) a.begin(), a.end()
#define lb(a, x) lower_bound(a.begin(), a.end(), x)
#define pb(x) push_back(x)
#define fr(i, n) for (int i = 0; i < n; ++i)
#define fr1(i, n) for (int i = 1; i <= n; ++i)
const int N = 1<<17;
/*
ll a[N];
int par[N], sz[N];
int get_p(int v) {
    if (par[v] == v) return v;
    else return par[v] = get_p(par[v]);
}
bool merge(int u, int v) {
    u = get_p(u);
    v = get_p(v);
    if (u == v) return false;
    if (sz[u] > sz[v]) swap(u, v);
    par[u] = v;
    sz[v] += u;
    return true;
}*/
vi g[N];
bool vis[N];
set<int> st;
void dfs(int v) {
    vis[v] = 1;
    vi el;
    for (auto it : g[v]) {
        if (st.find(it) != st.end()) {
            st.erase(it), el.push_back(it);
        }
    }
    vi can;
    for (auto it : st) can.push_back(it);
    st.clear();
    while (!el.empty()) {
        st.insert(el.back());
        el.pop_back();
    }
    
    for (auto it : can) dfs(it);
}
void solve() {
    int n; cin >> n;
    int m; cin >> m;
    fr(i, m) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    fr1(i, n) st.insert(i);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            st.erase(i);
            dfs(i), ++cnt;
        }
    }
    cout << cnt-1;
    /*ll n; cin >> n;
    int cnt = 0;
    for (ll i = 2; i*i <= n; ++i) {
        if (n %i == 0) {
            if (n / i == i)a[cnt++] = i;
            else a[cnt++] = i, a[cnt++] = n / i;
        }
    }
    if (cnt == 0) {
        cout << n;
        return;
    }
    sort(a, a + cnt);
    ll b = a[0];
    set<int> st;
    for (int i = 0; i < b; ++i) st.insert(i);
    for (int i = 1; i < cnt; ++i) {
        ll � = a[i];
        ll step = c % b;

    }*/

}
void pre_calc() {
    //fr(i, N) sz[i] = 1, par[i] = i;
}
int main() {
    pre_calc();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef ABCD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    //cout << -1;
    int tst = 1;
    if (tst != 1) cin >> tst;
    while (tst--)
        solve();
}
