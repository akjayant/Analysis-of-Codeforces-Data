#include <bits/stdc++.h>
using namespace std;
#define pb  push_back
#define ll  long long
#define vi  vector<ll >
#define vvi vector<vi >
#define all(x) x.begin(), x.end()

ll a, b, c, d, k;

void solve() {
    cin >> a >> b >> c >> d >> k;
    for (ll x = 0; x <= k; ++x) {
        ll y = k - x;
        if (c * x >= a && d * y >= b) {
            cout << x << " " << y << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
