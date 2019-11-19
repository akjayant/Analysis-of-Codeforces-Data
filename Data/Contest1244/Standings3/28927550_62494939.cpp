// Crt. 2019-10-13  17:04:28
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1, y = 0; return ;}
    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
}

int main() {
#ifdef whyqx
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif
    ll n, p, w, d;
    cin >> n >> p >> w >> d;

    ll x = p / w;
    ll tmp = x - d - 1;
    while (x >= 0 && x >= tmp) {
        ll res = p - x * w;
        if (res % d == 0) {
            ll y = res / d;
            if (x + y > n || x < 0 || y < 0) return puts("-1");
            else return cout << x << " " << y << " " << n - x - y << endl, 0;
        }
        x--;
    }
    puts("-1");

    return 0;
}
