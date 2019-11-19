#include <cstdio>

int main() {
    int T; scanf("%d", &T); while (T--) {
        int n, m, x; scanf("%d", &n);
        int T0 = 0, T1 = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x % 2) T1++; else T0++;
        }
        scanf("%d", &m);
        int S0 = 0, S1 = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &x);
            if (x % 2) S1++; else S0++;
        }
        printf("%lld\n", (long long)S0 * T0 + (long long)S1 * T1);
    }
    return 0;
}
