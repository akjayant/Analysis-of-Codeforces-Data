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
}
void solve() {
    ll n; cin >> n;
    int cnt = 0;
    int sst = 0;
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
    for (ll i = 2; i*i <= n; ++i) {
        if (n %i == 0) {
            ++sst;
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) ++sst;
    if (sst >= 2) {
        cout << 1;
        return;
    }
    if (sst == 1) {
        cout << a[0];
        return;
    }

    
    if (cnt == 1) {
        cout << a[0];
        return;
    }
    cout << 1;/*
    sort(a, a + cnt);
    ll b = a[0];
    set<int> st;
    for (int i = 0; i < b; ++i) st.insert(i);
    for (int i = 1; i < cnt; ++i) {
        ll � = a[i];
        ll step = c % b;

    }
    */
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
