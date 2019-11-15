#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> v(n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (i % 2) v[n - 1 - j % n].push_back(i * n + j);
        else v[j % n].push_back(i * n + j);
    }

    for (auto &w : v) {
        for (auto e : w) std::cout << e + 1 << " ";
        std::cout << std::endl;
    }

    return 0;
}
