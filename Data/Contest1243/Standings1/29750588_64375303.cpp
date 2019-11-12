#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define int long long

const int INF = 1e18;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int r = n + 1;
    int l = 0;
    while (r - l > 1) {
        int m = (r + l) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < m) {
                cnt = 0;
            } else {
                cnt++;
                if (cnt >= m) {
                    l = m;
                    break;
                }
            }
            if (i == n - 1) {
                r = m;
            }
        }
    }
    cout << l << '\n';
}

int32_t main() {
#ifdef local
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    while (q --) solve();
    return 0;
}