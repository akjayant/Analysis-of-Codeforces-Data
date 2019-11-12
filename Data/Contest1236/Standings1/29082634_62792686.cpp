#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

long long mul(long long x, long long y) {
    return (x * y) % MOD;
}

long long substract(long long x, long long y) {
    return (x - y + MOD) % MOD;
}

long long power(long long n, long long k) {
    long long rtn = 1;
    for (long long i = 1LL << 31; i; i >>= 1) {
        rtn = mul(rtn, rtn);
        if (k & i) rtn = mul(rtn, n);
    }
    return rtn;
}

int getans(int n, int m) {
    long long rtn = 0;
    return power(substract(power(2, m), 1), n);
    return rtn;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", getans(n, m));
    return 0;
}
