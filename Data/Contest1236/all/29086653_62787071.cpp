#include <bits/stdc++.h>

using namespace std;

#define long long long int 

long mod = 1e9 + 7;

long mul(long a, long b) {
    return (a * b) % mod;
}

long add(long a, long b) {
    return (a + b + mod) % mod;
}

long bpow(long n, long k) {
    long res = 1;
    while (k > 0) {
        if (k % 2) {
            res = mul(res, n);
            k--;
        }
        else {
            n = mul(n, n);
            k /= 2;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    long n, m;
    cin >> n >> m;

    cout << bpow(add(bpow(2, m), -1), n);
   
    return 0;
}