#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll qpow(ll a, int b) {
    ll c = 1;
    while (b) {
        if (b & 1) c *= a; c %= mod;

        b /= 2;
        a *= a; a %= mod;
    }
    return c;
}

int main() {

    ll n, m; scanf("%lld%lld", &n, &m);

    printf("%lld\n", qpow(qpow(2, m) - 1, n));

    return 0;
}