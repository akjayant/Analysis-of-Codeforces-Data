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
const int N = 400001;
int a[N];
bool in[N];
pii nl[N], nr[N];
void solve() {
    fill(nl, nl + N, pii{ N, 0 });
    fill(nr, nr + N, pii{ N, 0 });
    int n; cin >> n;
    int k; cin >> k;
    fr(i, n) {
        char c; cin >> c;
        a[i] = c == 'W';
    }
    fr(i, n) in[i] = (a[i] == a[(i + 1) % n] || a[i] == a[(i - 1 + n) % n]);
    bool flg = 0;
    fr(i, n) flg |= in[i];
    if (flg == 0) {
        fr(i, n) {
            cout << ((a[i]^(k&1)) == 0 ? 'B' : 'W');
        }
        return;
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (in[i%n]) nr[i] = { 0, a[i%n] };
        if (i) {
            if (nr[i - 1].first != N) {
                if (nr[i - 1].first + 1 < nr[i].first) {
                    nr[i].first = nr[i - 1].first + 1;
                    nr[i].second = nr[i - 1].second;
                }
            }
        }
    }
    for (int i = 2 * n - 1; i >= 0; --i) {
        if (in[i%n]) nl[i] = { 0, a[i%n] };
        if (i != 2*n-1) {
            if (nl[i + 1].first != N) {
                if (nl[i + 1].first + 1 < nl[i].first) {
                    nl[i].first = nl[i + 1].first + 1;
                    nl[i].second = nl[i + 1].second;
                }
            }
        }
    }
    fr(i, n) nl[i] = min(nl[i], nl[i + n]);
    fr(i, n) nr[i] = min(nr[i], nr[i + n]);
    fr(i, n) {
        if (in[i]) cout << (a[i] == 0 ? 'B' : 'W');
        else {
            pii d = min(nr[i], nl[i]);
            if(d.first <= k) cout << (d.second == 0 ? 'B' : 'W');
            else {
                cout << (((k & 1)^a[i]) == 0? 'B' : 'W');
            }
        }
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
