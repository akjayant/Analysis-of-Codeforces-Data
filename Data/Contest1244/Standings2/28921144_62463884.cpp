#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
using namespace std;
const ll maxn = 100001;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    for (int d1 = 0; d1 < t; d1++) {
        ll a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        ll r = (a + c - 1) / c;
        ll ka = (b + d - 1) / d;
        if (r + ka <= k) {
            cout << r << " " << ka << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
