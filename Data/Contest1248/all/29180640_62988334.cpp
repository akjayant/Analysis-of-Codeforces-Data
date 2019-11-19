#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<long long> st(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> st[i];
    }

    std::sort(st.begin(), st.end());
    long long s1 = 0, s2 = 0;

    for (int i = 0; i < n; ++i) {
        if (2 * i < n - 1) {
            s1 += st[i];
        } else {
            s2 += st[i];
        }
    }

    std::cout << s1 * s1 + s2 * s2 << "\n";

    return 0;
}
