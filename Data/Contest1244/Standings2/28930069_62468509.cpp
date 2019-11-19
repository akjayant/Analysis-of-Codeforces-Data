#include <bits/stdc++.h>
//haha

using namespace std;

#define int int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
int INF = 1e9 + 50;
int gcd(int a, int b) {
    while (b) {
        int p = a;
        a = b;
        b = p % b;
    }
    return a;
}

signed main() {
    fastio
// fileio
    int t;
    cin >> t;
    for (int qc = 0; qc < t; ++qc) {
        int n;
        cin >> n;
        string b;
        cin >> b;
        int f = n;
        int l = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] == '1') {
                f = min(i, f);
                l = max(i, l);
            }
        }
        if (f == n) {
            cout << n << '\n';
            continue;
        }
        if (f == l) {
            cout << max({2 * (f + 1), n, 2 * (n - l)}) << '\n';
            continue;
        }
        cout << max({2 * f + (l - f + 1) * 2, 2 * (n - 1 - l) + (l - f + 1) * 2}) << '\n';
    }
}