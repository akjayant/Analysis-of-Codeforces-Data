/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse4")*/
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
mt19937 rnd(random_device{}());
#define all(a) a.begin(), a.end()
#define lb(a, x) lower_bound(a.begin(), a.end(), x)
#define pb(x) push_back(x)
#define fr(i, n) for (int i = 0; i < n; ++i)
#define fr1(i, n) for (int i = 1; i <= n; ++i)
#define graf_init(u, v) int u, v; cin >> u >> v; g[u].push_back(v), g[v].push_back(u);
const int N = 100001;
ll c[N][3];
int deg[N];
vi g[N];
int ind[N];
void dfs(int u, int p, int i = 0) {
    ind[i] = u;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u, i + 1);
    }
}
int ans[N];
int n;
void clr(int cl, ll sm) {
    fr(i, n) {
        ans[ind[i]] = cl;
        cl = (cl + 1) % 3;
    }
    cout << sm << "\n";
    fr(i, n) cout << ans[i + 1] + 1 << " ";

}
void clr2(int cl, ll sm) {
    fr(i, n) {
        ans[ind[i]] = cl;
        cl = (cl + 2) % 3;
    }
    cout << sm << "\n";
    fr(i, n) cout << ans[i + 1] + 1 << " ";

}
void solve() {
    cin >> n;
    fr(i, n) cin >> c[i+1][0];
    fr(i, n) cin >> c[i+1][1];
    fr(i, n) cin >> c[i+1][2];
    fr(i, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int S = 0;
    fr(i, n) {
        if (deg[i + 1] == 1) S = i + 1;
        if (deg[i + 1] > 2) {
            cout << -1;
            return;
        }
    }
    dfs(S, S, 0);
    int cl = 0;
    ll sm1 = 0, sm2 = 0, sm3 = 0;
    ll ssm1 = 0, ssm2 = 0, ssm3 = 0;
    int cl2 = 0;
    fr(i, n) {
        sm1 += c[ind[i]][cl];
        sm2 += c[ind[i]][(cl+1)%3];
        sm3 += c[ind[i]][(cl+2)%3];
        ssm1 += c[ind[i]][cl2];
        ssm2 += c[ind[i]][(cl2 + 1) % 3];
        ssm3 += c[ind[i]][(cl2 + 2) % 3];
        cl++;
        cl %= 3;
        cl2 += 2;
        cl2 %= 3;
    }
    ll mn = sm1;
    mn = min(mn, min(sm2, min(sm3, min(ssm1, min(ssm2, min(ssm3, mn))))));
    if (sm1 == mn) {
        clr(0, sm1);
        return;
    }
    if (sm2 == mn) {
        clr(1, sm2);
        return;
    }
    if (sm3 == mn) {
        clr(2, sm3);
        return;
    }
    if (ssm1 == mn) {
        clr2(0, ssm1);
        return;
    }
    if (ssm2 == mn) {
        clr2(1, ssm2);
        return;
    }
    if (ssm3 == mn) {
        clr2(2, ssm3);
        return;
    }
   
    
}
void pre_calc() {
}
int main() {
    pre_calc();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef ABCD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    int tst = 1;
    if (tst != 1) cin >> tst;
    while (tst--)
        solve();
}
