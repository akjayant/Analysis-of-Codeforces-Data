#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int mn = n, mx = 0;
        for (int i = 0; i < n; i ++) if (s[i] == '1') mn = min(mn, i), mx = max(mx, i);
        if (mn == n && mx == 0) {cout << n << "\n"; continue;}
        cout << max(n, max(max(n - mx, mx + 1), max(n - mn, mn + 1)) * 2) << "\n";
    }
}
