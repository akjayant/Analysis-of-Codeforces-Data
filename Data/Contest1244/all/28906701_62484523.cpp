#include <bits/stdc++.h>
#define int long long
#define TTT long long
#define all(x) x.begin(), x.end()
#define forn(n) for (int i = 0; i < n; i++)
#define cint [&](){TTT x; cin >> x; return x;}()
using namespace std;

const int N = 1e5 + 1;
void trymax(int& x, int y) {
    x = max(x, y);
}
void trymin(int& x, int y) {
    x = min(x, y);
}

int can[N];

signed main () {
    int n, p, w, d;
    cin >> n >> p >> w >> d;

    for (int i = p / w; i >= 0; i--) {
        int x = i * w;
        if (i + (p - w * i) / d > n) break;
        if (can[(p - w * i) % d]) break;
        can[(p - w * i) % d] = true;
        if ((p - x) % d == 0 && n - (i + (p - x) / d) >= 0) {
                int xx = (p - x) / d;
                int yy = i;
                if (xx * d + yy * w != p) continue;
                if (xx + yy > n) continue;
            return cout << yy << ' ' << xx << ' ' << n - xx - yy << endl, 0;
        }
    }
    cout << -1;
}
