#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        int a, b;
        scanf("%d %d", &a, &b);
        int g = gcd(a, b);
        if (g == 1) {
            printf("Finite\n");
        } else {
            printf("Infinite\n");
        }
    }

    return 0;
}
