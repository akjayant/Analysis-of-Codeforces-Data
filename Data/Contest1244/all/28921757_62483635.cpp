#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-O3")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define pb push_back
#define F first
#define S second
#define lll long long
#define lld long double

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree <T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 2e5 + 229;
const lll M = 1e18 + 3;
const lll M2 = 1e9 + 9;
const int mod = 998244353;
const int rx[4] = {1, -1, 0, 0};
const int ry[4] = {0, 0, 1, -1};
const lld eps = 1e-18;
const double pi = acos(-1.0);

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("game.in", "r", stdin);
//    freopen("game.out", "w", stdout);
#endif
    lll n, p, w, d;
    cin >> n >> p >> w >> d;
    lll x, y, z;
    lll KEK = 30000000;
    for (int i = 0; i <= KEK; ++i) {
        x = i;
        if (x * w <= p) {
            y = (p - (x * w)) / d;
            if (x * w + y * d == p && x + y <= n) {
                cout << x << ' ' << y << ' ' << n - x - y;
                return 0;
            }
        }
        y = i;
        if (y * d <= p) {
            x = (p - (y * d)) / w;
            if (x * w + y * d == p && x + y <= n) {
                cout << x << ' ' << y << ' ' << n - x - y;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
