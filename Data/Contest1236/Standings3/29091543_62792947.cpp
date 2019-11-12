#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (int) 1e9 + 7;

ll power(ll x, ll y) {
    if (y == 0) return 1LL;
    if (y % 2) return ((x % mod) * power(x, y - 1)) % mod;
    return power((x * x) % mod, y / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    cout << power((power(2, m) - 1 + mod) % mod, n) << '\n';

    return 0;
}