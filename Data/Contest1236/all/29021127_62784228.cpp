#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int caseNum; cin >> caseNum;
    while (caseNum--) {
       int a, b, c, ans = 0; cin >> a >> b >> c;
        for (int x = 0; x <= 200; x++) {
            for (int y = 0; y <= 200; y++) {
                if (x <= a && 2 * x + y <= b && 2 * y <= c) {
                    ans = max(ans, 3 * (x + y));
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}