#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair <int, int>;

const int oo = INT_MAX;
const int SZ = 2e5 + 4;

int t, n, a, b, d;

void read() {
    cin >> t;
}

string s, ans;

void solve() {
    while (t--) {
        cin >> n >> a >> b >> d >> s;
        int k = 0, w = 0;
        ans = "";
        for (auto c : s) {
            if (c == 'R') {
                if (!b) ans += 'x';
                else b--, ans += 'P', w++;
            }
            if (c == 'P') {
                if (!d) ans += 'x';
                else d--, ans += 'S', w++;
            }
            if (c == 'S') {
                if (!a) ans += 'x';
                else a--, ans += 'R', w++;
            }
        }

        if (w * 2 >= n) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (ans[i] == 'x') {
                    if (a) a--, ans[i] = 'R';
                    else if (b) b--, ans[i] = 'P';
                    else if (d) d--, ans[i] = 'S';
                }
            }
            cout << ans << endl;
        } else cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
}
