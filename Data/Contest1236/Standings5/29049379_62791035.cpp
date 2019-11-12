#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

LL pow_mod(LL x, LL p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}
int main() {
    LL n, m;
    cin >> n >> m;
    cout << pow_mod(pow_mod(2, m) - 1 + mod, n) << endl;
    return 0;
}
