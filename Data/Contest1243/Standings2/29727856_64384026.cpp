#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef LOCAL
    FILE *f = freopen("input", "r", stdin);\
    freopen("output", "w", stdout);
#endif
    const int cnt = 'z' - 'a' + 1;

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        vector<int> tmp;

        for (int i = 0; i < n && tmp.size() < 2; ++i) {
            if (s[i] != t[i])
                tmp.push_back(i);
        }

        if (tmp.size() > 2) {
            cout << "No\n";
        } else if (tmp.size() == 2) {
            swap(t[tmp[0]], s[tmp[1]]);
            if (s == t) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else if (tmp.size() == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}