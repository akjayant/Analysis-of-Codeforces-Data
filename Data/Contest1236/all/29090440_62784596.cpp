#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cas;
    cin >> cas;
    while (cas--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        while (b > 0) {
            if (b >= 1 && c >= 2) {
                b--;
                c -= 2;
                ans += 3;
            } else {
                break;
            }
        }

        while (a > 0) {
            if (a >= 1 && b >= 2) {
                a--;
                b -= 2;
                ans += 3;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}