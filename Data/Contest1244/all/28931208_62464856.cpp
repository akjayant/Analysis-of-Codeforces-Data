#include <iostream>
#include <vector>
#include <functional>
#include <set>
#include <numeric>
#include <queue>
#include <unordered_set>

using namespace std;

void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int flag = 0, x, y;
    for (int i = 0; !flag && i <= k; ++i) {
        for (int j = k - i; !flag && j >= 0; --j) {
            if (i * c >= a && j * d >= b) {
                flag = 1;
                x = i;
                y = j;
            }
        }
    }
    if (flag) {
        cout << x << ' ' << y << '\n';
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}