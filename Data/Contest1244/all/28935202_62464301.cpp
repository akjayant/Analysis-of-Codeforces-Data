#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c, d, k;
        std::cin >> a >> b >> c >> d >> k;
        for (int i = 0; i <= k; i++) {
            if (c * i >= a && d * (k - i) >= b) {
                std::cout << i << " " << k - i << std::endl;
                goto next;
            }
        }
        std::cout << -1 << std::endl;
next:;
    }

    return 0;
}
