#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;

long long qpow(long long a, long long b) {
    long long ans = 1;
    while(b) {
        if(b&1)
            ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%lld\n", qpow((qpow(2, m)-1+mod)%mod, n));
    return 0;
}