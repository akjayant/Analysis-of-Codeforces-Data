#include <bits/stdc++.h>

#define need_long 1

#define all(v) v.begin(), v.end()
#define vc vector
#define len(v) ((int) v.size())
#define pr pair
#define ld long double
#define mset multiset

using namespace std;

#if need_long == 1
#define int long long
#else
#endif
const int INF = (need_long) ? 1e18 : 2e9;
mt19937 gen(time(0));

template <class T> int upmax(T &a, T b) {
    return (b > a) ? a = b, 1 : 0;
}

template <class T> int upmin(T &a, T b) {
    return (b < a) ? a = b, 1 : 0;
}

template <class T> void output(vc<T>&a, ostream &out = cerr, string r = " ") {
    for (int i = 0; i < len(a); ++i) {
        cout << a[i] << r;
    }
    out << "\n";
}

const int MAXN = 3e5 + 40;
const int LOG = 30;

const int MOD = 1e9 + 7;

int add(int a, int b) {
    return (a + b) % MOD;
}

int dp[MAXN];

void solve() {
    string s;
    cin >> s;
    s = '#' + s;
    dp[0] = 1;
    for (int i = 1; i < len(s); ++i) {
        if (s[i] == 'w') {
            cout << 0;
            return;
        }
        if (s[i] == 'm') {
            cout << 0;
            return;
        }
        dp[i] = add(dp[i], dp[i - 1]);
        if (i > 1 && s[i] == 'u' && s[i - 1] == 'u') dp[i] = add(dp[i], dp[i - 2]);
        if (i > 1 && s[i] == 'n' && s[i - 1] == 'n') dp[i] = add(dp[i], dp[i - 2]);
    }
    cout << dp[len(s) - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}