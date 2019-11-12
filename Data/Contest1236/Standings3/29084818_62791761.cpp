#include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n >> m;
    long long p = 1'000'000'007;
    cout << power(power(2, m, p) - 1, n, p) << '\n';
    return 0;
}
