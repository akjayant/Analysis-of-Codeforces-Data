#include <iostream>

#define prime 1000000007

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    long long a = 1;
    long long b = 1;
    long long result = -1;

    for (int i = 1; i <= n || i <= m; ++i) {
        if (i == n) {
            result += b;
        }

        if (i == m) {
            result += b;
        }

        long long c = (a + b) % prime;
        a = b;
        b = c;
    }

    std::cout << (2 * result) % prime << "\n";
    return 0;
}
