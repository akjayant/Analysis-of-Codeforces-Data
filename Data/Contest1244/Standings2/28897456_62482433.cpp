//#pragma GCC target ("avx2,sse2")
//#pragma GCC optimization ("Ofast")
//#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define db long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fi first
#define se second
#define mp make_pair
#define endl "\n"
//#define int long long
using namespace std;

void dout() {
    cerr << endl;
}

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = (int)1e5 + 7, inf = (int)1e9 + 100;
int n, a[N];
ll k;

ll get(int x, int y) {
    int l = y, r = x + y, mn = inf, mx = -inf;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        if (a[i] >= l && a[i] <= r) {
            continue;
        }
        res += min(abs(a[i] - l), abs(a[i] - r));
    }
    if (mn > l) {
        res += mn - l;
        if (mn > r) {
            res -= mn - r;
        }
    }
    if (mx < r) {
        res += r - mx;
        if (mx < l) {
            res -= l - mx;
        }
    }
    return res;
}

bool check(int x) {
    int l = 1, r = (int)1e9 + 5;
    while (l < r) {
        int mid = (l + r) / 2;
        if (get(x, mid) > get(x, mid + 1)) {
            l = mid + 1;
        }   else {
            r = mid;
        }
    }
    return get(x, l) <= k;
}

void solve(int tc) {
    cin >> n >> k;
    int mn = inf, mx = -inf;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    int l = -1, r = mx - mn + 1;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        }   else {
            l = mid;
        }
    }
    cout << r;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int tc = 1;
//    cin >> tc;
    for (int i = 0; i < tc; i++) {
        solve(i);
//        cleanup();
    }
}
