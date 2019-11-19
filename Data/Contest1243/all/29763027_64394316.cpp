#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m;

map<ll, int> pfac;


int main() {
    cin >> m;
    int nf = 0;
    ll n = m;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0LL) {
            nf += 1;
        }
        while (n % i == 0LL) {
            n /= i;
            pfac[i] += 1;
        }
    }
    if (n > 1) {
        pfac[n] = 1;
        nf += 1;
    }
    if (nf >= 2) {
        cout << 1 << "\n";
    } else if (m == 1) {
        cout << 1 << "\n";
        }
        else if (nf == 1) {
        ll fac = 0;
        for (auto factors: pfac) {
            fac = factors.first;
        }
        cout << fac << "\n";
    }
}