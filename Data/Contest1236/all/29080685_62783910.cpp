#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int ret = 0;
        for (int i = 0; i <= 50; i++) for (int j = 0; j <= 50; j++) {
            int na = i, nb = i * 2 + j, nc = j * 2;
            if (na <= a && nb <= b && nc <= c) ret = std::max(ret, na + nb + nc);
        }
        std::cout << ret << std::endl;
    }

    return 0;
}
