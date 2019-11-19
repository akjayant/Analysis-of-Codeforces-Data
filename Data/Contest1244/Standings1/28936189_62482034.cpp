#include <bits/stdc++.h>

long long n, m, a, b, x, y, gcd, min = 1e18;

int main() {
    scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
    for (long long i = 0, j; i <= 1000000; i++) {
        j = m - b * i;
        if (j % a == 0) {
            j /= a;
            if (i >= 0 && j >= 0) { min = std::min(min, i + j); }
        }
    }
    if (min == 1e18) { printf("-1\n"); return 0; }
    for (long long i = 0, j; i <= 1000000; i++) {
        j = m - b * i;
        if (j % a == 0) {
            j /= a;
            if (i >= 0 && j >= 0 && min == i + j) { x = j; y = i; }
        }
    }
    if (n - x - y >= 0) {
        printf("%lld %lld %lld\n", x, y, n - x - y);
    } else {
        printf("-1\n");
    }
    return 0;
}