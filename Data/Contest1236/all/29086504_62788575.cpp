#include <bits/stdc++.h>

using namespace std;
#define int long long
#define EPS 1e-6
#define mod 1000000007


int fpow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        int res = fpow(a, b / 2);
        return res * res % mod;
    } else {
        int res = fpow(a, b - 1);
        return res * a % mod;
    }
}

signed main() {
    int n, m;
    cin >> m >> n;
    cout << fpow(fpow(2, n) - 1 , m);
}