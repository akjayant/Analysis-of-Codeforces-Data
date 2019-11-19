#include <cstdio>
#include <iostream>
using namespace std;

int read();

char s[2003];

int main() {
    int t = read();
    while (t--) {
        int n = read();
        scanf("%s", s + 1);
        int res = n;
        for (int i = 1; i <= n; ++i)
            if (s[i] == '1') res = max(res, 2 * max(i, n - i + 1));
        printf("%d\n", res);
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