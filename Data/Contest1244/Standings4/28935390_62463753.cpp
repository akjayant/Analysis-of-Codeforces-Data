//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("O3")
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define sqr(a) (a * a)
#define ll long long
#define ull unsigned long long
#include <bits/stdc++.h>
using namespace std;
//#define int long long

void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    int x = (a + c - 1) / c;
    int y = (b + d - 1) / d;

    if (x + y > k) {
        cout << "-1\n";
        return;
    }

    x += k - x - y;

    cout << x << ' ' << y << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    srand(time(0));
    //freopen("river.in", "r", stdin);
    //freopen("river.out", "w", stdout);
    
    int tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
    
}