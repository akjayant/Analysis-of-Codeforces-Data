#include <bits/stdc++.h>

using namespace std;

#define MS(a, b) memset(a, b, sizeof(a))
#define REP(a, b, c) for (register int a = b, _n = c; a <= _n; ++a)
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

int T;

int main () {
    T = rd();
    while (T--) {
        int a = rd(), b = rd(), c = rd(), d = rd(), k = rd();
        bool f = 1;
        REP (i, 0, k) if (c * i >= a && (k - i) * d >= b) {
            f = 0;
            printf ("%d %d\n", i, k - i);
            break;
        }
        if (f) puts("-1");
    }

    return 0;
}
