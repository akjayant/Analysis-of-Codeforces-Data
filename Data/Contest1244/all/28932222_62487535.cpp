
#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>

const size_t N = 100050;
long long int a[N];
int main() {
    long long int n, k;
    std::cin >> n >> k;

    for (long long int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a, a + n);

    long long int ll = 0;
    long long int lr = 0;

    long long int rl = n - 1;
    long long int rr = n - 1;

    long long int min = a[ll];
    long long int max = a[rr];

    while (k > 0 && min != max) {
        while (min == a[lr]) {
            ++lr;
        }
        long long lc = lr;

        while (a[rl] == max) {
            --rl;
        }
        long long rc = n - rl - 1;

        if (k < std::min(lc, rc)) {
            break;
        }

        if (lc < rc) {
            long long v = std::min(k / lc, a[lr] - min);
            min += v;
            k -= v * lc;
        } else {
            long long v = std::min(k / rc, max - a[rl]);
            max -= v;
            k -= v * rc;
        }
        // std::cout << min << " " << max << " " << k << std::endl;
    }

    std::cout << (max - min);

    return 0;
}