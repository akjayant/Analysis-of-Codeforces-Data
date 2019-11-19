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
const int rx[4] = {0, 0, -1, 1};
const int ry[4] = {-1, 1, 0, 0};
const lld eps = 1e-7;
const double pi = acos(-1.0);

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

lll calc[N];

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
    calc[1] = 2;
    calc[2] = 4;
    for (int i = 3; i < N; ++i) {
        calc[i] = (calc[i - 1] + calc[i - 2]) % M;
    }
    int n, m;
    cin >> n >> m;
    lll ans = calc[m];
    ans += calc[n] - 2;
    ans %= M;
    cout << ans;
    return 0;
}
