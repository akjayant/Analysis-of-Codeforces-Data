#include<bits/stdc++.h>

const int MOD = 1e9 + 7;

int FastPow(int a, int b) {
    int res = 1;
    for(; b; b >>= 1, a = 1LL * a * a % MOD)
        if(b & 1) res = 1LL * res * a % MOD;
    return res;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", FastPow((FastPow(2, m) - 1 + MOD) % MOD, n));
    return 0;
}
