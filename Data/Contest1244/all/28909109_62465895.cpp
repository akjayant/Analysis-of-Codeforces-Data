#include <bits/stdc++.h>

#define ll long long
ll MOD = 1000000007;

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int ans = 0, ans1 = 0;
        ans += a / c;
        ans1 += b / d;
        if (a % c != 0) ans++;
        if (b % d != 0) ans1++;
        if (ans + ans1 > k) {
            cout << -1 << endl;
        } else {
            cout << ans << " " << ans1 << endl;
        }
    }
    return 0;
}