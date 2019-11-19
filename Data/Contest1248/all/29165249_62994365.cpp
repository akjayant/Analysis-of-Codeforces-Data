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

int n;

string t;

int pref[N], suf[N];

int need1[N], need2[N];

int solve() {
    vector < char > st;
    int f;
    int need = 0;
    for (int i = 0; i < n; ++i) {
        if (!st.empty() && st.back() == '(' && t[i] == ')') {
            st.pop_back();
        } else {
            st.pb(t[i]);
            if (t[i] == ')') {
                ++need;
            }
        }
        if (st.empty()) {
            f = 1;
        } else if (st.back() == ')') {
            f = 0;
        } else {
            f = -1;
        }
        pref[i] = f;
        need1[i] = need;
    }
    int ans = (pref[n - 1] == 1);
    need = 0;
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        if (!st.empty() && st.back() == ')' && t[i] == '(') {
            st.pop_back();
        } else {
            st.pb(t[i]);
            if (t[i] == '(') {
                ++need;
            }
        }
        if (st.empty()) {
            f = 1;
        } else if (st.back() == '(') {
            f = 0;
        } else {
            f = -1;
        }
        suf[i] = f;
        need2[i] = need;
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (pref[i] == 1 && suf[i + 1] == 1) {
            ++ans;
            continue;
        }
        if (pref[i] == -1 || suf[i + 1] == -1) {
            continue;
        }
        if (need1[i] == need2[i + 1]) {
            ++ans;
        }
    }
    return ans;
}

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
    cin >> n >> t;
    pair < int, pair < int, int > > best, now;
    best.S = {1, 1};
    best.F = solve();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(t[i], t[j]);
            now.F = solve();
            now.S.F = i + 1;
            now.S.S = j + 1;
            swap(t[i], t[j]);
            best = max(best, now);
        }
    }
    cout << best.F << '\n' << best.S.F << ' ' << best.S.S;
    return 0;
}
