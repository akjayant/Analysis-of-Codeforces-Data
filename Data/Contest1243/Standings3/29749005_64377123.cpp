#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 15;

int _, n, a[maxn];

int main() {
    cin >> _;
    while (_--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            int tar = lower_bound(a, a + n, i) - a;
            if (n - tar >= i) {
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

