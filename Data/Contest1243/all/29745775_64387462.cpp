#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long long;

int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll x = -1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            x = i;
            break;
        }
    }
    if (x == -1) cout << n << endl;
    else {
        while (n % x == 0) {
            n /= x;
        }
        if (n == 1) cout << x;
        else cout << 1;
    }
}
