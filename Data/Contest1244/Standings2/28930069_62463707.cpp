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
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1) / c;
        int y = (b + d - 1) / d;
        if (x + y <= k) {
            cout << x << ' ' << y << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}