#include <bits/stdc++.h>

#define ll long long
ll MOD = 1000000007;

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;

        cin >> s;
        bool ones = false;
        for (char c : s)
            if (c == '1') ones = true;
        if (!ones)
            cout << n << endl;
        else {
            int ff = n, l = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    l = i;
                    ff = min(ff, i);
                }
            }
            cout << 2 * (max(n - ff, l + 1)) << endl;
        }
    }
    return 0;
}