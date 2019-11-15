#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector <vector <int> > ans(n);
    int now = 1;
    int i = 0, fl = 0;
    while (now <= n * n) {
        ans[i].push_back(now);
        now++;
        if (!fl)
            i++;
        else
            i--;
        if (i == n) {
            fl ^= 1;
            i--;
        }
        else if (i == -1) {
            i++;
            fl ^= 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto el : ans[i])
            cout << el << " ";
        cout << "\n";
    }
    return 0;
}
