#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;

long long int fastPow(long long int a, long long int n, long long int mod) {
    long long int ret = 1; a %= mod;
    while (n > 0) {
        if (n & 1)
            ret = (ret * a) % mod;
        a = (a * a) % mod; n >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long int giftNum, boxNum; cin >> giftNum >> boxNum;
    cout << fastPow(fastPow(2, boxNum, mod) - 1, giftNum, mod) << '\n';
 
    return 0;
}