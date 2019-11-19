#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll i = 2;
    ll ans = n;
    vector<ll> all;
    while (i * i <= n) {
        if (n % i == 0) {
            all.push_back(i);
        }
        while (n % i == 0) {
            ans = i;
            n /= i;
        }
        i++;
    }
    if (n != 1) {
        all.push_back(n);
    }

    if (ans == n) {
        cout << n;
    } else {
        if (all.size() > 1) {
            cout << 1;
        } else {
            cout << all[0];
        }
    }

    return 0;
}
