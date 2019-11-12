#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
const int mod = 1000000000 + 7;
long long qpow(long long a, long long k) {
    long long res = 1;
    while (k) {
        if (k & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}
int main() {
    long long n, m; scanf("%lld%lld", &n, &m);
    long long ans = qpow((qpow(2, m) - 1 + mod) % mod, n);
    printf("%lld\n", ans);
    getchar(); getchar();
    return 0;
}