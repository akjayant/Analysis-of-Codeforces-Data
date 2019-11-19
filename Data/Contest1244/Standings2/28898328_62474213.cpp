#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define ld long double
#define ll long long
#define TIME 1.0*clock()/CLOCKS_PER_SEC

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;
const ll MOD = 1e9 + 7;
const int rx[4] = {-1, 0, 1, 0};
const int ry[4] = {0, 1, 0, -1};
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int hx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int hy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const ld eps = 1e-7;
const double pi = acos(-1.0);
const int INF = 1e9;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll pos = -1;
    for (int x = 0; x <= 100000; x++) {
        if (x * w <= p && (p - (x * w)) % d == 0) {
            pos = x;
            break;
        }
    }
    if (pos == -1) {
        cout << "-1" << endl;
        return 0;
    }
    ll x = pos;
    p -= x * w;
    ll nok = (w / __gcd(w, d)) * d;
    x += (nok / w) * (p / nok);
    p %= nok;
    ll y = p / d;
    if (x + y <= n) {
        cout << x << " " << y << " " << n - x - y << endl;
    } else cout << "-1" << endl;
    return 0;
}
