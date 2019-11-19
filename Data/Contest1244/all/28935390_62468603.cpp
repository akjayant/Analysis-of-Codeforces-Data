//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("O3")
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define sqr(a) (a * a)
#define ll long long
#define ull unsigned long long
#include <bits/stdc++.h>
using namespace std;
//#define int long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[j] != '1')
                continue;
            ans = max(ans, abs(i - j) + 1 + max(j + 1, n - j));
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    srand(time(0));
    //freopen("river.in", "r", stdin);
    //freopen("river.out", "w", stdout);
    
    int tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
    
}