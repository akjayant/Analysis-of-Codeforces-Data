#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100010;
const int mod = 1e9 + 7;
long long f[N];
int main() {
    int n, m;
    scanf("%d %d", &m, &n);
    f[1] = f[0] = 1;
    for(int i = 2; i <= max(n, m); i++)
        f[i] = (f[i-1] + f[i-2]) % mod;
    long long ans = ((f[n] + f[m] - 1) % mod) * 2 % mod;
    printf("%lld\n", ans);
    return 0;
}