#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        std::vector<int> a;
        int n;
        std::cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            a.push_back(x);
        }
        std::sort(a.rbegin(), a.rend());
        int res = 0;
        for (int j = 0; j < n; j++) {
            res = max(res, min(a[j], j + 1));
        }
        std::cout << res << '\n';
    }
}
