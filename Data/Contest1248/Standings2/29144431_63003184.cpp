#include <cstdio>

const int mod = 1e9 + 7;
const int kN = 100005;
long long fib[kN], sum_fib[kN];

void init() {
    fib[1] = fib[2] = 1;
    sum_fib[1] = 1;
    sum_fib[2] = 2;
    for(int i = 3; i < kN; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
        sum_fib[i] = sum_fib[i - 1] + fib[i];
    }
}

int main() {
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%lld", (2ll * (fib[n + 1] + sum_fib[m - 1])) % mod);
    return 0;
}