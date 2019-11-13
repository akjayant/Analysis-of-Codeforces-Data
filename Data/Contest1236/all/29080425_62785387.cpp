#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

bool MULTI_TEST = true;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i <= a && 2 * i + j <= b && 2 * j <= c) {
                ans = max(ans, 3 * (i + j));
            }
        }
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

