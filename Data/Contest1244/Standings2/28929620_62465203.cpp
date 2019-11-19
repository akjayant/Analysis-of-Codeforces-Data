#include <cstdio>
#include <iostream>
using namespace std;

int read();

int main() {
    int T = read();
    while (T--) {
        int a = read(), b = read(), c = read(), d = read(), k = read();
        int r1 = (a - 1) / c + 1, r2 = (b - 1) / d + 1;
        if (r1 + r2 <= k)
            printf("%d %d\n", r1, r2);
        else
            puts("-1");
    }
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}