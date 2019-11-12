#include <bits/stdc++.h>
using i64 = long long;

template <typename T, typename U, typename V>
constexpr auto pow(T x_, U n_, V mod_) {
    std::common_type_t<T, U, V> ret = 1, x = x_, n = n_, mod = mod_;
    while(n > 0) {
        if ((n & 1) == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

template <typename T, typename U>
constexpr auto inverse(T x, U p) { return pow(x, p - 2, p); }

int main() {
    constexpr i64 mod = 1000000007;
    i64 n, m;
    std::cin >> n >> m;
    i64 ret = (pow(2, m, mod) + mod - 1) % mod;
    ret = pow(ret, n, mod);
    std::cout << ret << std::endl;

    return 0;
}
