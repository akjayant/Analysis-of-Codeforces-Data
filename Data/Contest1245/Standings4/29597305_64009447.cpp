// CF A
// DeP
#include <cstdio>

int gcd(int a, int b) {
    return !b? a: gcd(b, a % b);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        puts(gcd(a, b) == 1? "Finite": "Infinite");
    }
    return 0;
}
