#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int g = __gcd(a, b);
        printf(g == 1 ? "Finite\n" : "Infinite\n");
    }
}