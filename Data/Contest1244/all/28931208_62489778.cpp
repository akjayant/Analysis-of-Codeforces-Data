#include <iostream>
#include <vector>
#include <functional>
#include <set>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;
typedef long long ll;

vector<int> help(int a, int d, int c) {
    vector<int> r;
    for (int i = 0; i < c; ++i) {
        if ((i * (long long)a) % c == d) {
            r.push_back(i);
        }
    }
    return r;
}

void solve() {
    int64_t n, p;
    int w, d;
    cin >> n >> p >> w >> d;
    auto val = help(w % d, p % d, d);
    if (val.empty() || val[0] > n || (long long)w * val[0] > p) {
        cout << "-1\n";
        return;
    }
    for (auto x : val) {
        if ((long long)x * w > p)
            break;
        ll rig = p - (ll)x * w;
        rig /= d;
        ll k = max(0LL, (rig + x - n + w - d - 1) / (w - d));
        ll y = rig - k * w;
        if (y >= 0 && k * d + y + x <= n && w * (k * d + x) + d * y == p) {
            cout << k * d + x << ' ' << y << " " << n - k * d - y - x << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}