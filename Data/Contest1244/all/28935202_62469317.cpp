#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;
        auto l = s.find_first_of('1'), r = s.find_last_of('1');
        if (l == std::string::npos) {
            std::cout << n << std::endl;
        } else {
            std::cout << (int)std::max(n - l, r + 1) * 2 << std::endl;
        }
    }

    return 0;
}
