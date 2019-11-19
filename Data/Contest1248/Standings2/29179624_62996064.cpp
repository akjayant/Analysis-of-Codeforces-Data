#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int p = 1e9 + 7;
typedef long long ll;
ll n, m, f[maxn];

int main() {
    scanf("%lld %lld", &n, &m);
    f[1] = 1, f[2] = 2;
    if (n < m) swap(n, m);
    for (int i = 3; i <= n; ++i) f[i] = (f[i - 1] + f[i - 2]) % p;
    printf("%lld\n", (f[n] + f[m] + p - 1) * 2 % p);
    return 0;
}