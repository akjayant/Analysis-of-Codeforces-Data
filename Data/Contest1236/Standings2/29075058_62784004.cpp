#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                int A = a - i;
                int B = b - 2 * i - j;
                int C = c - 2 * j;
                if (A < 0 || B < 0 || C < 0) continue;
                ans = max(ans, 3 * (i + j));
            }
        }
        cout << ans << '\n';
    }
}
