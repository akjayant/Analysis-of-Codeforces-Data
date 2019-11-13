#include <bits/stdc++.h>
using i64 = long long;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << (gcd(a, b) == 1 ? "Finite" : "Infinite") << std::endl;
    }

    return 0;
}
