#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair

using namespace std;

int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 1) {
        return (a * binpow(a, b - 1)) % mod;
    } else {
        long long h = binpow(a, b / 2);
        return (h * h) % mod;
    }
}

int main() {
    long long n, m;
    cin >> n >> m;
    cout << binpow((binpow(2ll, m) - 1), n);
    return 0;
}
