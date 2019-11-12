#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int add(int a, int b) {
    return (1LL * a + b) % mod;
}

int radd(int a, int b) {
    int res = a - b;
    if (res < 0) {
        res += mod;
    }

    return res;
}

int binpow(int a, int n) {
    int res = 1;
    while(n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int ans = radd(binpow(2, m), 1);
    ans = binpow(ans, n);

    cout << ans << "\n";
    return 0;
}
/*
*/
