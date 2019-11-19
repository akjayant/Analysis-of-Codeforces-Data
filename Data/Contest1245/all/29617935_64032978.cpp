#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e3 + 5;

int l, r, tota, totb, a[N], b[N];
long long ans, pwr[N];

long long solve(int n, int m) {
    if (n < 0) { return 0; }
    long long res = 0; 
    long long res00 = 1;
    long long res01 = 0;
    long long res10 = 0;
    long long res11 = 0;
    for (int i = pwr[0] = 1; i <= 30; i++) { pwr[i] = pwr[i - 1] * 3; }
    for (int i = 30; i >= 0; i--) { a[i] = b[i] = 0; }
    tota = totb = 0;
    for (int i = n; i; i /= 2) { a[tota++] = i % 2; }
    for (int i = m; i; i /= 2) { b[totb++] = i % 2; }
    for (int i = 30; i >= 0; i--) {
        if (a[i] == 1 && b[i] == 1) {
            res += res00 * pwr[i];
            res += res01 * pwr[i] * 2;
            res += res10 * pwr[i] * 2;
            res01 += res00;
            res10 += res00;
            res00 = 0;
        }
        if (a[i] == 1 && b[i] == 0) {
            res10 <<= 1;
            res10 += res00;
            res += res01 * pwr[i] * 2;
        }
        if (a[i] == 0 && b[i] == 1) {
            res01 <<= 1;
            res01 += res00;
            res += res10 * pwr[i] * 2;
        }
        if (a[i] == 0 && b[i] == 0) {
            res10 <<= 1;
            res01 <<= 1;
        }
    }
    return res + res00 + res01 + res10;
}

int main() {
    for (int T = read(); T; T--) {
        l = read(); r = read();
        ans = 0;
        ans += solve(r, r);
        ans += solve(l - 1, l - 1);
        ans -= solve(l - 1, r) * 2;
        printf("%lld\n", ans);
    }
    return 0;
}