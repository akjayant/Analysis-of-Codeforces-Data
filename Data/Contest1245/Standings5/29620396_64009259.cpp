#include <bits/stdc++.h>

inline int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    int T_T;
    scanf("%d", &T_T);
    while (T_T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (gcd(a, b) == 1) puts("Finite");
        else puts("Infinite");
    }
    return 0;
}