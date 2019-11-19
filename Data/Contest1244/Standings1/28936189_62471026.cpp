#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n, l, r;
std::string str;

int main() {
    for (int T = read(); T; T--) {
        n = read(); std::cin >> str;
        l = -1; r = -1;
        for (int i = 0; i < n; i++) {
            if (str[i] == '1') {
                if (l == -1) { l = i; } r = i;
            }
        }
        if (l == -1) {
            printf("%d\n", n);
        } else {
            printf("%d\n", std::max(n - l, r + 1) * 2);
        }
    }
    return 0;
}