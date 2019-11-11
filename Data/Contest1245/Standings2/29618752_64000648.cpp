#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b, c, w = 0;
        cin >> n >> a >> b >> c;

        string s;
        cin >> s;

        char ans[s.length()];
        fill(ans, ans + s.length(), '0');
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                if (b)
                    b--, ans[i] = 'P', w++;
            } else if (s[i] == 'P') {
                if (c)
                    c--, ans[i] = 'S', w++;
            } else {
                if (a)
                    a--, ans[i] = 'R', w++;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (ans[i] == '0') {
                if (a)
                    a--, ans[i] = 'R';
                else if (b)
                    b--, ans[i] = 'P';
                else
                    c--, ans[i] = 'S';
            }
        }

        if (w >= ceil(n / 2.0)) {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << ans[i];
            cout << "\n";
        } else
            cout << "NO\n";
    }
}