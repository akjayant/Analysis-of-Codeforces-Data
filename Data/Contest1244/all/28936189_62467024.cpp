#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n, a, b, c, d;

int main() {
    for (int T = read(); T; T--) {
        a = read(); b = read(); c = read(); d = read(); n = read();
        a = (a - 1) / c + 1; b = (b - 1) / d + 1;
        if (a + b <= n) {
            printf("%d %d\n", a, b);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}