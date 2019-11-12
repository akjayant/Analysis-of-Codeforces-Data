#include<bits/stdc++.h>

//#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(v) (int) v.size()

using namespace std;

const int N = 1005;

int n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, min(i, a[i]));
    }
    cout << ans << "\n";
}

main() {
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
