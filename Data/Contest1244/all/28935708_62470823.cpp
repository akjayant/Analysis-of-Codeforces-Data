#include <bits/stdc++.h>

using namespace std;

#define MS(a, b) memset(a, b, sizeof(a))
#define REP(a, b, c) for (int a = b, _n = c; a <= _n; ++a)
#define DREP(a, b, c) for (register int a = b, _n = c; a >= _n; --a)
#define FOR(a, b, c) for (register int a = b, _n = c; a < _n; ++a)
#define EREP (a, b) for (register int a = head[b]; a; a = edge[a].nxt)

inline int rd () {
    int x = 0; bool f = 0; char IO = getchar();
    while ((IO < '0' || IO > '9') && IO != '-') IO = getchar();
    if (IO == '-') IO = getchar(), f = 1;
    while (IO >= '0' && IO <= '9') x = (x << 3) + (x << 1) + (IO ^ 48), IO = getchar();
    return f ? -x : x;
}

const int SIZE = 1005;

int T;
int n;
char a[SIZE];

int main () {
    scanf ("%d", &T);

    while (T--) {
        scanf ("%d%s", &n, a + 1);
        int ans = n;
        REP (i, 1, n) if (a[i] == '1')
            ans = max(ans, max(i, n - i + 1) * 2);
        printf ("%d\n", ans);
    }
    return 0;
}
