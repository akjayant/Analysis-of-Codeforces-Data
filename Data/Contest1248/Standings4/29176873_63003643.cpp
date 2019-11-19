#include <iostream>
#include <cstdio>
const int MAXN = 5e5 + 7;
typedef long long ll;
const int mod = 1e9 + 7;
ll x[MAXN], b[MAXN], c[MAXN];
void init()
{
    x[1] = b[2] = c[2] = 2; x[2] = 4;
    b[1] = c[1] = 0;
    for (int i = 3; i <= 100000; i++) {
        x[i] = (x[i - 1] + x[i - 2]) % mod;
        b[i] = (b[i - 1] + b[i - 2]) % mod;
        c[i] = (c[i - 1] + b[i]) % mod;
    }
}
int main()
{
    init();
    ll n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", (x[n] + c[m]) % mod);
    return 0;
}
