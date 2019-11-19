#include <bits/stdc++.h>
#define N ((int)1e6+10)
#define MD ((int)1e9+7)

using namespace std;
int a, b, c, d, q, k, n;

int main() {
    string s;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        cin >> s;
        int f = -1, e = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (f == -1) {
                    f = i;
                }
                e = i;
            }
        }
        if (f == -1) {
            cout << n << endl;
        } else {
            int mx = (n - f) * 2;
            mx = max(mx, (e + 1) * 2);
            cout << mx << endl;
        }
    }

    return 0;
}
