#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int inf = 1e9;

int add(int x, int y) {
    return (1ll * x + 1ll * y) % mod;
}

int del(int x, int y) {
    return ((1ll * x - 1ll * y) % mod + mod) % mod;
}

int mul(int x, int y) {
    return (1ll * x * 1ll * y) % mod;
}

int binpow(int x, int m) {
    if(m == 0)
        return 1;
    else if(m == 1)
        return x;
    else {
        int sum = binpow(x, m / 2);
        sum = mul(sum, sum);
        if(m % 2)
            sum = mul(sum, x);
        return sum;
    }
}

signed main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int alo = del(binpow(2, m), 1);
    cout << binpow(alo, n);
}
