#include <bits/stdc++.h>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x = 1001, y = 1001;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                x = min(x, i);
                y = n - 1 - i;
            }
        }
        if (x == 1001 && y == 1001) {
            cout << n << endl;
            continue;
        }
        cout << 2 * n - 2 * min(x, y) << endl;
    }
}