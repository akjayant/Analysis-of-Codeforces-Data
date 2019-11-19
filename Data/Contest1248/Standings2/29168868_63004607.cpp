#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const ll mod = 1e9 + 7;

ll dp1[N], dp2[N];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    if(n > m) swap(n, m); // promise n <= m
    dp1[1] = 1LL;
    for(int i = 2; i <= m; i++) dp1[i] = (dp1[i - 1] + dp1[i - 2]) % mod;
    dp2[2] = 1LL;
    for(int i = 3; i <= m; i++) dp2[i] = (dp2[i - 1] + dp2[i - 2]) % mod;
    ll ans = 0LL;
    if(n == 1) {
        ans = (dp1[m] + dp2[m]) % mod;
        printf("%lld\n", 2LL * ans % mod);
        return 0;
    }
    ans += dp1[m] + dp2[m] - 1; ans %= mod;
    ans += dp1[n] + dp2[n]; ans %= mod;
    printf("%lld\n", 2LL * ans % mod);
}
