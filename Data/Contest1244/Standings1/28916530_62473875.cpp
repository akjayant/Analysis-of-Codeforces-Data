#include <bits/stdc++.h>
using namespace std;
#define pb  push_back
#define ll  long long
#define vi  vector<ll >
#define vvi vector<vi >
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

ll n, p, w, d, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> w >> d;
    ll g = gcd(w, d);
    if (p % g) {
        cout << -1;
        return 0;
    }
    w /= g;
    d /= g;
    p /= g;

    y = 0;
    while ((p - y * d) % w) ++y;
    x = (p - y * d) / w;

    if (x < 0 || x + y > n) {
        cout << -1;
        return 0;
    }
    cout << x << " " << y << " " << n - x - y;

    return 0;
}
