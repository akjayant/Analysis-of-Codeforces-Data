// CF A
// DeP
#include <cstdio>

const int MAXN = 1e5+5;

int n, m;
int N1, N2, M1, M2;
int p[MAXN], q[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        N1 = N2 = M1 = M2 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", p+i);
            if (p[i] & 1) ++N1;
            else ++N2;
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d", q+i);
            if (q[i] & 1) ++M1;
            else ++M2;
        }
        printf("%I64d\n", 1LL * N1 * M1 + 1LL * N2 * M2);
    }
    return 0;
}
