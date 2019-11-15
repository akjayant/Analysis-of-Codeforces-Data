#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const long long mod = 1e9 + 7;

long long fastpow(long long x, long long deg) {
    if (deg == 0)
        return 1;
    else if (deg == 1)
        return x % mod;
    long long half = fastpow(x, deg / 2);
    if (deg % 2)
        return (((half * half) % mod) * x) % mod;
    return (half * half) % mod;
}

int main() {
    long long n, m;

    cin >> n >> m;
    cout << fastpow(fastpow(2, m) - 1, n) << endl;

    return 0;
}