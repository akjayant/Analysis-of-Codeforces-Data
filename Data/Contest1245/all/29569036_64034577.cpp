//#pragma GCC target ("avx2,sse2")
//#pragma GCC optimization ("Ofast")
//#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree <int, null_type, less_equal <int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define db long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fi first
#define se second
#define mp make_pair
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define endl "\n"

#define left fsdkfsdfsdfd
#define sum dfsdfsdfsdf
#define assign sdkfskdfkk

#define int long long

using namespace std;

void dout() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

int bit(signed x) {
    return __builtin_popcount(x);
}
int bit(ll x) {
    return __builtin_popcountll(x);
}

const int K = 30;
int l, r, dp[K][2][2][2][2];
vector <int> L, R;

void precalc() {
    L = {};
    R = {};
    do {
        L.pb(l & 1);
        l >>= 1;
    }   while (l);
    while (L.size() < K) {
        L.pb(0);
    }
    reverse(L.begin(), L.end());

    do {
        R.pb(r & 1);
        r >>= 1;
    }   while (r);
    while (R.size() < K) {
        R.pb(0);
    }
    reverse(R.begin(), R.end());
}

int calc(int n, int f1, int f2, int g1, int g2) {
    if (n == K) {
        return 1;
    }
    int & res = dp[n][f1][f2][g1][g2];
    if (res != -1) {
        return res;
    }
    res = 0;
    // 1 0
    if (!(f2 && R[n] == 0) && !(g1 && L[n] == 1)) {
        res += calc(n + 1, (f1 && (L[n] == 1)), (f2 && (R[n] == 1)), (g1 && (L[n] == 0)), (g2 && (R[n] == 0)));
    }
    // 0 1
    if (!(f1 && L[n] == 1) && !(g2 && R[n] == 0)) {
        res += calc(n + 1, (f1 && (L[n] == 0)), (f2 && (R[n] == 0)), (g1 && (L[n] == 1)), (g2 && (R[n] == 1)));
    }
    // 0 0
    if (!(f1 && L[n] == 1) && !(g1 && L[n] == 1)) {
        res += calc(n + 1, (f1 && (L[n] == 0)), (f2 && (R[n] == 0)), (g1 && (L[n] == 0)), (g2 && (R[n] == 0)));
    }
    return res;
}

void solve(int tc) {
    // check for (int i = 0; i < n; j++)
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    for (int h = 0; h < 2; h++) {
                        dp[i][j][k][l][h] = -1;
                    }
                }
            }
        }
    }
    cin >> l >> r;
    precalc();
    cout << calc(0, 1, 1, 1, 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int tc = 1;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        solve(i);
//        cleanup();
    }
}
