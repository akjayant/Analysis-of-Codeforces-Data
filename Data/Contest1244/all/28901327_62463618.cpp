#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

ll INF = (ll) 1e20;
int iINF = (int) 1e20;
ll mod = (ll) 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t
    ;cin >> t;
    while(t--) {
        ll a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if((a + c - 1) / c + (b + d - 1) / d <= k) {
            cout << (a + c - 1) / c << ' ' << (b + d - 1) / d << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}
