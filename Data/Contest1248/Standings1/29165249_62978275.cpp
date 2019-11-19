//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define pb push_back
#define F first
#define S second
#define lll long long
#define lld long double

//#define int lll

using namespace std;
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree <T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const int N = 2e5 + 223;
const int M = 1e9 + 7;
const lll M2 = 1e9 + 9;
const int mod = 998244353;
const int rx[8] = {1, 1, -1, -1, -2, -2, 2, 2};
const int ry[8] = {-2, 2, -2, 2, 1, -1, 1, -1};
const lld eps = 1e-7;
const double pi = acos(-1.0);

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

lll a[N];

main() {
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
    int n;
    cin >> n;
    lll now1 = 0, now2 = 0;
    int k1 = 0, k2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        now2 += a[i];
        ++k2;
    }
    sort(a, a + n);
    lll ans = 0;
    for (int i = 0; i < n; ++i) {
        now2 -= a[i];
        now1 += a[i];
        ++k1;
        --k2;
        if (n % 2) {
            if (abs(k1 - k2) == 1) {
                ans = max(ans, now2 * now2 + now1 * now1);
            }
        } else if (k1 == k2) {
            ans = max(ans, now2 * now2 + now1 * now1);
        }
    }
    cout << ans;
    return 0;
}
