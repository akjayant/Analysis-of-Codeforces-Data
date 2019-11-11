#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair <int, int>;

const int oo = INT_MAX;
const int SZ = 2e5 + 4;

void read() {
}

int t, a, b;

void solve() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (__gcd(a, b) == 1) {
            cout << "Finite" << endl;
        } else cout << "Infinite" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
}
