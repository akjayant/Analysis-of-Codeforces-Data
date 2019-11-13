#include <bits/stdc++.h>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mp make_pair
#define sqr(s) ((s) * (s))
 
using namespace std;
 
typedef complex<int> point;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int a, b, c;
    int ans = 0;
    cin >> a >> b >> c;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (a < i || b < 2 * i + j || c < 2 * j)
                continue;
            ans = max(ans, 3 * i + 3 * j);
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
        solve();
}
