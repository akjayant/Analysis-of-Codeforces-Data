#include <cstdio>
#include <algorithm>
#include <iostream>

const int mod = 1e9 + 7;

using ll = long long; 

int inc(int a, int b) {
    return a + b >= mod ? a + b - mod : a + b;
}

int pow(int a, int b) {
    int res = 1; 
    while (b) {
        if (b & 1) res = (ll) res * a % mod; 
        a = (ll) a * a % mod; 
        b >>= 1;
    }
    return res; 
}

int main() {
    
    int n, m;
    scanf("%d%d", &n, &m);

    int ans = inc(pow(2, m), mod - 1);
    ans = pow(ans, n);

    printf("%d\n", ans);
}