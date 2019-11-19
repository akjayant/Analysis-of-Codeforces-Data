#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        long long P[2] = {0, 0};
        long long Q[2] = {0, 0};
        
        for (int i = 0, a; i < n; ++i) {
            std::cin >> a;
            P[a & 1]++;
        }

        int m;
        std::cin >> m;

        for (int i = 0, a; i < m; ++i) {
            std::cin >> a;
            Q[a & 1]++;
        }

        std::cout << P[0]*Q[0] + P[1]*Q[1] << "\n";
    }

    return 0;
}
