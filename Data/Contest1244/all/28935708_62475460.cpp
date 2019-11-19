#include <bits/stdc++.h>

using namespace std;

#define MS(a, b) memset(a, b, sizeof(a))
#define REP(a, b, c) for (register int a = b, _n = c; a <= _n; ++a)
#define DREP(a, b, c) for (register int a = b, _n = c; a >= _n; --a)
#define FOR(a, b, c) for (register int a = b, _n = c; a < _n; ++a)
#define EREP (a, b) for (register int a = head[b]; a; a = edge[a].nxt)
#define LL long long

inline int rd () {
    int x = 0; bool f = 0; char IO = getchar();
    while ((IO < '0' || IO > '9') && IO != '-') IO = getchar();
    if (IO == '-') IO = getchar(), f = 1;
    while (IO >= '0' && IO <= '9') x = (x << 3) + (x << 1) + (IO ^ 48), IO = getchar();
    return f ? -x : x;
}

LL n, p, w, d;

LL exgcd (LL a, LL b, LL& x, LL& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    LL g = exgcd(b, a % b, y, x);
    y = y - a / b * x;
    return g;
}

LL x, y;

int main () {
    scanf ("%lld%lld%lld%lld", &n, &p, &w, &d);
    LL g = exgcd(w, d, x, y);
    if (p % g) {
        puts("-1");
        return 0;
    }
    p /= g, d /= g, w /= g;
    x = (x * (p % d) % d + d) % d;
    y = (p - x * w) / d;

    if (n - x - y >= 0 && y >= 0) {
        printf ("%lld %lld %lld\n", x, y, n - x - y);
        return 0;
    }


    y = (y % w + w) % w;
    x = (p - y * d) / w;

    if (n - x - y >= 0 && x >= 0) {
        printf ("%lld %lld %lld\n", x, y, n - x - y);
        return 0;
    }
    
    puts("-1");

    return 0;
}
