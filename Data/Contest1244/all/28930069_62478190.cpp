#include <bits/stdc++.h>
//haha

using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
int INF = 1e9 + 50;
int gcd(int a, int b) {
    while (b) {
        int p = a;
        a = b;
        b = p % b;
    }
    return a;
}

signed main() {
    fastio
// fileio
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    int gcd1 = gcd(w, d);
    if (p % gcd1 != 0) {
        cout << -1 << '\n';
        return 0;
    }
    p /= gcd1;
    d /= gcd1;
    w /= gcd1;
    if (p == 0) {
        cout << 0 << ' ' << 0 << ' ' << n;
        return 0;
    }
    if (p < d) {
        cout << -1;
        return 0;
    }
    if (p < w) {
        if (p % d) {
            cout << -1 << '\n';
        } else {
            int y = p / d;
            if (y > n) {
                cout << -1 << '\n';
                return 0;
            }
            cout << 0 << ' ' << y << ' ' << n - y << '\n';
        }
        return 0;
    }
    int ost = p % d;
    int how = 0;
    while (how < d && (how * w) % d != ost) ++how;
    if (how == d) {
        cout << -1;
        return 0;
    }
    int osth = how % d;
    int x = p / w / d * d + osth;
    while (w * x > p) {x -= d;}
    int y = (p - x * w) / d;
    int z = n - x - y;
    if (z >= 0 && x >= 0 && y >= 0 && x * w + y * d == p) {
        cout << x << ' ' << y << ' ' << z;
        return 0;
    }
    cout << -1;
}