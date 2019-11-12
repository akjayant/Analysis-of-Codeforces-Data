#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int oo = 1e9;
// const LL oo = 1e16 + 5;
const int MOD = 1e9 + 7;
const int N = 2e5+5;
// const int MOD = 998244353;
// const long double PI = acos(-1);

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    int ans = 0;
    for (x=0;x<=a;x++) for (y=0;2 * y<=c;y++) if (2 * x + y <= b) {
        ans = max(ans, 3 * (x + y));
    }
    cout << ans << '\n';
}

int main() {
    FASTIO; int t = 1; 
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve();
    }
    return 0;
}