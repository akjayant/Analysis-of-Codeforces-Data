#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
const int mod = 1e9 +7;
ll dp[N][2];
ll f[N];
ll qpow(ll base, ll n){
    ll ans = 1;
    while (n){
        if (n & 1) ans = ans * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    f[1] = 2;
    f[2] = 4;
    for (int i = 3; i <= max(n, m); ++ i) f[i] = (f[i - 1] + f[i - 2]) % mod;
    ll ans = (f[n] + f[m] - 2) % mod;
    printf("%I64d\n", ans);
    return 0;
}

