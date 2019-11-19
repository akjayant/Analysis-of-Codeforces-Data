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

long long n, p, w, d;

const int N = 1e7 + 5;

signed main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> p >> w >> d;
    for(int x = 0; x <= min(N - 5, n); x++) {
        long long val = p - x * w;
        if(val >= 0 && val % d == 0) {
            int y = val / d, z = n - y - x;
            if(x >= 0 && y >= 0 && z >= 0 && x * w + y * d == p && x + y + z == n) {
                cout << x << " " << y << " " << z << "\n";
                exit(0);
            }
        }
    }
    for(int y = 0; y <= min(N - 5, n); y++) {
        long long val = p - y * d;
        if(val >= 0 && val % w == 0) {
            int x = val / w, z = n - y - x;
            if(x >= 0 && y >= 0 && z >= 0 && x * w + y * d == p && x + y + z == n) {
                cout << x << " " << y << " " << z << "\n";
                exit(0);
            }
        }
    }
    cout << "-1\n";
}
