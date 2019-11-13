#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pll pair<ll, ll>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;

        string s1, s2(m, '0');
        cin >> s1;
        int x = 0;
        for (int i = 0; i < m; i++) {
            auto ch = s1[i];
            if (ch == 'R' && b) {
                s2[i] = 'P';
                b--;
                x++;
            } else if (ch == 'P' && c) {
                s2[i] = 'S';
                c--;
                x++;
            } else if (ch == 'S' && a) {
                s2[i] = 'R';
                a--;
                x++;
            }
        }
        for (auto& ch: s2) {
            if (ch == '0') {
                if (a) {
                    ch = 'R';
                    a--;
                } else if (b) {
                    ch = 'P';
                    b--;
                } else {
                    ch = 'S';
                    c--;
                }
            }
        }
        if (x >= (m+1)/2) {
            cout << "YES\n" << s2 << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}