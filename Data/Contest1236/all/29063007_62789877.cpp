#include<bits/stdc++.h>

#define ll long long
using namespace std;
const ll N = 2e5 + 5;

ll power(ll x, unsigned ll y, ll p) {
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
    // equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (1LL * res * x) % p;

        // y must be even now
        y = y >> 1LL; // y = y/2
        x = (x * x * 1LL) % p;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    cout << power((power(2, m, 1e9 + 7) - 1), n, 1e9 + 7);
    return 0;
}