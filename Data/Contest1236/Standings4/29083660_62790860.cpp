#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long powmod(long long x, long long n) {
    long long ret = 1;
    while(n > 0) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long n, m;
    cin >> n >> m;
    cout << powmod(powmod(2LL, m) - 1LL, n) << '\n';
}