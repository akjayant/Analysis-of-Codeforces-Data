#include <bits/stdc++.h>

#define ll long long
ll MOD = 1000000007;

using namespace std;

int main() {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll x = p / w, y = LLONG_MAX;
    for (int i = 0; i < d + 5; i++) {
        if ((p - x * w) % d == 0) {
            y = (p - x * w) / d;
            break;
        }
        x--;
    }
    if (y != LLONG_MAX && x + y <= n && x >= 0) {
        cout << x << " " << y << " " << n - x - y;
    } else {
        cout << -1;
    }

    return 0;
}