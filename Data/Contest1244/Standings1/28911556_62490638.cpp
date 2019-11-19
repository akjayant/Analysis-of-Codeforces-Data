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
map<int, int> mp;
void solve() {
    ll n, k; cin >> n >> k;
    fr(i, n) {
        int v; cin >> v;
        mp[v]++;
    }
    while (mp.size() > 1) {
        auto it1 = mp.begin();
        auto it2 = mp.rbegin();
        ll x = it1->second;
        ll posx = it1->first;
        ll posy = it2->first;
        ll y = it2->second;
        it1++;
        it2++;
        if (x > k && y > k) break;

        if (x < y) {
            ll sh = k / ((ll)x);
            sh = min(sh, (ll)it1->first - posx);
            k -= sh * x;
            mp.erase(posx);
            mp[posx + sh] += x;
        }
        else {
            ll sh = k / ((ll)y);
            sh = min(sh, (ll)posy - it2->first);
            k -= sh * y;
            mp.erase(posy);
            mp[posy - sh] += y;
        }
    }
    if (mp.size() == 1) cout << 0;
    else cout << (mp.rbegin()->first - mp.begin()->first);
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
