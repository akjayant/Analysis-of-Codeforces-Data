#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-6

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    while (b >= 1 && c >= 2) {
        b--;
        c -= 2;
        ans+=3;
    }
    while (a >= 1 && b >= 2) {
        a--;
        b -= 2;
        ans+=3;
    }
    cout << ans<<"\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}