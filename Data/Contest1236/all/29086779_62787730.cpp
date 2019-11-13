// Standard libraries
#include <stdio.h>
#include <vector>

typedef long long int lld;

const lld mod = 1'000'000'007;

lld power(lld x, lld n){
    if(n==0) return 1;
    lld half = power(x, n/2);
    if(n%2==0) return half*half%mod;
    else return half*half%mod*x%mod;
}

// Main
int main(int argc, char **argv){
#ifdef __McDic__ // Local testing I/O
    freopen("VScode/IO/input.txt", "r", stdin);
    freopen("VScode/IO/output.txt", "w", stdout);
#endif

    lld n, m; scanf("%lld %lld", &n, &m);
    printf("%lld\n", power(power(2, m) - 1, n));
    return 0;
}