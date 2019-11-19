#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef arrias
    freopen("true.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int res = n;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                res = max(res, (i + 1) * 2);
                int left = (n - (i + 1) + 1);
                res = max(res, left * 2);
            }
        }
        cout << res << "\n";
    }
    return 0;
}
