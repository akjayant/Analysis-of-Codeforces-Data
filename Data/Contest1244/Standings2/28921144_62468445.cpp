#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
using namespace std;
const ll maxn = 21000;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    for (int d1 = 0; d1 < t; d1++) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll mx = n;
        for (int d = 0; d < s.size(); d++) {
            if (s[d] == '1') {
                mx = d;
                break;
            }
        }
        for (int d = s.size() - 1; d >= 0; d--) {
            if (s[d] == '1') {
                mx = min(mx, s.size() - 1ll - d);
                break;
            }
        }
        ll ans = max((n - mx) * 2, n);
        cout << ans << "\n";
    }
}
