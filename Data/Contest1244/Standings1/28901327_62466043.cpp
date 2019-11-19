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
        ll n;
        string s;
        cin >> n >> s;
        ll ans = n;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') {
                ans = max(ans, max((ll)i + 1, n - i) * 2);
            }
        }
        cout << ans << '\n';
    }
}
