#include <iostream>
#include <vector>
#include <functional>
#include <set>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ans = max(ans, max(2 * (i + 1), 2 * (n - i)));
        }
    }
    cout << ans << '\n';
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