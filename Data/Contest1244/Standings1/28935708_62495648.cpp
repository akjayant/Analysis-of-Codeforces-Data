#include <bits/stdc++.h>

using namespace std;

#define MS(a, b) memset(a, b, sizeof(a))
#define REP(a, b, c) for (register int a = b, _n = c; a <= _n; ++a)
#define DREP(a, b, c) for (register int a = b, _n = c; a >= _n; --a)
#define FOR(a, b, c) for (register int a = b, _n = c; a < _n; ++a)
#define EREP (a, b) for (register int a = head[b]; a; a = edge[a].nxt)
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define LL long long

inline int rd () {
    int x = 0; bool f = 0; char IO = getchar();
    while ((IO < '0' || IO > '9') && IO != '-') IO = getchar();
    if (IO == '-') IO = getchar(), f = 1;
    while (IO >= '0' && IO <= '9') x = (x << 3) + (x << 1) + (IO ^ 48), IO = getchar();
    return f ? -x : x;
}

const int SIZE = 100005;

int n;
LL k;
int a[SIZE];

LL sum[SIZE];

int main () {
    n = rd();
    scanf ("%lld", &k);

    REP (i, 1, n) a[i] = rd();
    sort(a + 1, a + n + 1);

    REP (i, 1, n) sum[i] = a[i] + sum[i - 1];

    int R = 1;

    while (R <= n && (sum[n] - sum[R - 1]) - 1LL * a[R] * (n - R + 1) > k)
        ++R;

    LL tmp = k - ((sum[n] - sum[R - 1]) - 1LL * a[R] * (n - R + 1));
    int ans = a[n] - a[1];
    int L = 1;
    ans = min(ans, max(0, a[R] - min(a[L + 1], a[L] + tmp / L)));
    ans = min(ans, max(0, max(a[R - 1], a[R] - tmp / (n - R + 1)) - a[L]));

    a[n + 1] = 2e9;
    a[0] = 2e9;
    REP (L, 2, n) {
        if (1LL * a[L] * L - sum[L] > k) break;
        LL x = k - (1LL * a[L] * L - sum[L]);
        while (R <= n && (sum[n] - sum[R - 1]) - 1LL * a[R] * (n - R + 1) > x)
            ++R;
        x -= (sum[n] - sum[R - 1]) - 1LL * a[R] * (n - R + 1);
        ans = min(ans, max(0, a[R] - min(a[L + 1], a[L] + x / L)));
        ans = min(ans, max(0, max(a[R - 1], a[R] - x / (n - R + 1)) - a[L]));
    }

    L = n;
    while (L >= 1 && 1LL * a[L] * L - sum[L] > k)
        --L;
    R = n;
    tmp = k - (1LL * a[L] * L - sum[L]);
    ans = min(ans, max(0, a[R] - min(a[L + 1], a[L] + tmp / L)));
    ans = min(ans, max(0, max(a[R - 1], a[R] - tmp / (n - R + 1)) - a[L]));

    DREP (R, n - 1, 1) {
        if ((sum[n] - sum[R - 1]) - 1LL * a[R] * (n - R + 1) > k) break;
        LL x = k - ((sum[n] - sum[R - 1]) - 1LL * a[R] * (n - R + 1));
        while (L >= 1 && 1LL * a[L] * L - sum[L] > x)
            --L;
        x -= (1LL * a[L] * L - sum[L]);
        ans = min(ans, max(0, a[R] - min(a[L + 1], a[L] + x / L)));
        ans = min(ans, max(0, max(a[R - 1], a[R] - x / (n - R + 1)) - a[L]));
    }


    printf ("%d\n", ans);

    return 0;
}
