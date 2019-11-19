#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

bool MULTI_TEST = true;

void solve() {
    vector<int> cnt1(2), cnt2(2);
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt1[x % 2]++;
    }
    int m;
    cin >> m;
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        cnt2[x % 2]++;
    }
    int ans = 0;
    for (int t : {0, 1}) {
        ans += cnt1[t] * cnt2[t];
    }
    cout << ans << endl;
}

signed main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    if (MULTI_TEST) {
        cin >> t;
    }
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
