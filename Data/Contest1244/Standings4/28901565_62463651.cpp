#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
const int maxn = 2e5 + 5;
signed main() {
    fast;
    srand(time(0));
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int p = a / c + (a % c != 0);
        int q = b / d + (b % d != 0);
        if (p + q <= k) {
            cout << p << ' ' << q << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}
