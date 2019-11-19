
#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        int right = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                right = i;
            }
        }

        int left = -1;
        for (int i = n -1; i >= 0; --i) {
            if (s[i] == '1') {
                left = i;
            }
        }

        if (left == -1) {
            std::cout << n << std::endl;
        } else {
            std::cout << 2 * std::max(n - left, right + 1) << std::endl;
        }
    }


    return 0;
}