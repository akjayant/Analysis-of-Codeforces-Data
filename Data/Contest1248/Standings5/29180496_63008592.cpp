#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
long long n, m;
long long p[maxn], ans[maxn];

int main(){
    p[0] = 2;
    p[1] = 0;
    p[2] = 2;
    ans[2] = 2;
    for(int i = 3; i < maxn; i++) {
        p[i] = (p[i-1] + p[i-2]) % mod;
        ans[i] = (ans[i-1] + p[i]) % mod;
    }

    scanf("%lld%lld", &n, &m);
    printf("%lld\n", (ans[n] + ans[m] + p[0]) % mod);

    return 0;
}
