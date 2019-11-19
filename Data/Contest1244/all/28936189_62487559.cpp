#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n;
long long ans = 1e18, k, a[N], sum[N];

inline long long get(int l, int r) {
    return sum[r] - sum[l - 1];
}

int main() {
    n = read(); k = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) { sum[i] = sum[i - 1] + a[i]; }
    for (int i = 1; i <= n; i++) {
        long long res = -1;
        for (long long l = 1, r = a[i], mid; l <= r; ) {
            mid = l + r >> 1;
            int p = std::upper_bound(a + 1, a + n + 1, mid) - a - 1;
            p = std::min(p, i);
            if (mid * p - get(1, p) + get(i, n) - a[i] * (n - i + 1) <= k) {
                l = mid + 1; res = mid;
            } else {
                r = mid - 1;
            }
        }
        if (res != -1) { ans = std::min(ans, a[i] - res); }
    }
    for (int i = 1; i <= n; i++) { a[i] = 1e9 + 5 - a[i]; }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) { sum[i] = sum[i - 1] + a[i]; }
    for (int i = 1; i <= n; i++) {
        long long res = -1;
        for (long long l = 1, r = a[i], mid; l <= r; ) {
            mid = l + r >> 1;
            int p = std::upper_bound(a + 1, a + n + 1, mid) - a - 1;
            p = std::min(p, i);
            if (mid * p - get(1, p) + get(i, n) - a[i] * (n - i + 1) <= k) {
                l = mid + 1; res = mid;
            } else {
                r = mid - 1;
            }
        }
        if (res != -1) { ans = std::min(ans, a[i] - res); }
    }
    printf("%I64d\n", ans);
    return 0;
}