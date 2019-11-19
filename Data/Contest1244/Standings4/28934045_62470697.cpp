#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int c = 0;
        int first = 1e8, last = -1e8;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                c++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                first = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                last = i;
                break;
            }
        }
        cout <<  max({n + c, (n - first) * 2, (last + 1) * 2}) << endl;
    }
}
