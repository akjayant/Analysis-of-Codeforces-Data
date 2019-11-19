#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

bool MULTI_TEST = false;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n / 2; i++) {
        s1 += a[i];
    }
    for (int i = n / 2; i < n; i++) {
        s2 += a[i];
    }
    cout << s1 * s1 + s2 * s2;
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
