#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair <int, int>;

const int oo = INT_MAX;
const int SZ = 2e5 + 4;
const ll M = 1e9 + 7;

string s;

void read() {
    cin >> s;
}

ll ans = 1;
ll res[SZ];

void solve() {
    int k = (s[0] == 'u' || s[0] == 'n');
    int n = s.size();
    res[0] = 1;
    for (int i = 1; i <= n; i++)
        res[i] = (res[i - 1] + (i > 1 ? res[i - 2] : 0)) % M;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0;
            return;
        }
        if (!i) continue;
        if (s[i] != s[i - 1]) {
            ans *= res[k];
            ans %= M;
            k = (s[i] == 'u' || s[i] == 'n');
        } else k += (s[i] == 'u' || s[i] == 'n');
    }
    ans *= res[k];
    ans %= M;
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
}
