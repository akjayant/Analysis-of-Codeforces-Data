#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define f first
#define s second

const int MAXN = 1e6 + 3;

int main() {
    long long n, p, d, w;
    scanf("%lld %lld %lld %lld", &n, &p, &w, &d);
    long long mx = n * w;
    long long y, z;
    if (mx > p) {
        y = (mx - p) / w;
        if ((mx - p) % w != 0)
            y++;
        mx -= y * w;
    }
    else if (mx < p) {
        printf("-1");
        return 0;
    }
    z = mx / w;
    for (long long i = 0; i <= max(d, w); i++) {
        if ((p - mx) % d == 0) {
            y = (p - mx) / d;
            if (y + z <= n) {
                printf("%lld %lld %lld", z, y, n - y - z);
                return 0;
            }
        }
        z--;
        mx -= w;
        if (mx < 0 || z < 0)
            break;
    }
    printf("-1");
    return 0;
}

