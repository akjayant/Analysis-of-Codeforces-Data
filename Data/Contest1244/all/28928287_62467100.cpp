#include <cstdio>
int main() {
    int t;
    for (scanf("%d", &t); t--; ) {
        int a, b, c, d, k, x, y;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        x = a / c + (int)!(!(a % c));
        y = b / d + (int)!(!(b % d));
        if (x + y <= k) {
            printf("%d %d\n", x, y);
        } else {
            puts("-1");
        }
    }
    return 0;
}
