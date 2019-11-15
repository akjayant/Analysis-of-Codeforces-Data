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

int test, a, b, c;

signed main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> test;
    while(test--) {
        cin >> a >> b >> c;
        int sum = 0;
        while(b >= 1 && c >= 2) {
            b--;
            c -= 2;
            sum += 3;
        }
        while(a >= 1 && b >= 2) {
            a--;
            b -= 2;
            sum += 3;
        }
        cout << sum << "\n";
    }
}
