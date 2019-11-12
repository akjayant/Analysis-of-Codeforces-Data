// qdd on Oct 17, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll qk(ll a, ll b, ll p) {
    ll ans = 1 % p;
    for (a %= p; b; b >>= 1) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    cout << qk(qk(2, m, MOD) + MOD - 1, n, MOD)<< '\n';
    return 0;
}