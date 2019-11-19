#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    std::vector<int> d;
    std::cin >> n;
    for (int j = 2; j * j <= n; j++) {
        if (n%j == 0) {
            d.push_back(j);
            if (n/j != j) d.push_back(n/j);
        }
    }
    if (d.size() == 0) {
        std::cout << n;
        return 0;
    }
    for (int i = 1; i < d.size(); i++) {
        if (d[i]%d[0] != 0) {
            std::cout << 1;
            return 0;
        }
    }
    std::cout << d[0];
}
