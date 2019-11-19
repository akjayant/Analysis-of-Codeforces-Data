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

ll gcdd (ll a, ll b) {
    while (b) {
        a %= b;
        swap (a, b);
    }
    return a;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, p, d, w;
    cin >> n >> p >> w >> d;
    if(p < w) {
        if(p % d == 0) {
            if (p / d <= n) {
                cout << 0 << ' ' << p / d << ' ' << n - p / d;
                return 0;
            }
        }
        cout << -1;
        return 0;
    }
    ll num = -1;
    ll now = w % d;
    for (int i = 0; i <= d + 5; ++i) {
        if (now == p % d) {
            num = i;
            break;
        }
        now = now + w;
        now %= d;
    }
    if (num == -1) {
        if (p % d == 0 && p / d <= n) {
            cout << 0 << ' ' << p / d << ' ' << n - p / d;
            return 0;
        }
        cout << -1;
        return 0;
    }
    ll kek = w * (num + 1);
    ll x = 0;
    ll nok = (d * w) / (gcdd(d, w));
    ll l = 0, r = p / nok + 100;
    while(l <= r) {
        ll m = (l + r) / 2;
        if(m * nok + kek <= p) {
            x = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    ll number = x * (nok / w);
//    cout << num + 1 << ' ' << kek << ' ' << x << ' ' << nok << ' ' << number << '\n';
    if (number + num + 1 + (p - (kek + x * nok)) / d <= n) {
        cout << number + (num + 1) << ' ' << ((p - kek - nok * x) / d) << ' ' << n - number - num - 1 - ((p - (kek + x * nok)) / d);
    } else {
        cout << -1;
    }
}
