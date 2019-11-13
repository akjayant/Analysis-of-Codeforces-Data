#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, dp[N][2];
string s;

void add (int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

bool ok (char c1, char c2) {
    return ((c1 == 'u' && c2 == 'u') || (c1 == 'n' && c2 == 'n'));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s; n = s.length(); s = "#" + s;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        add(dp[i][0], dp[i - 1][0]);
        add(dp[i][0], dp[i - 1][1]);
        if (i > 1 && ok(s[i], s[i - 1])) {
            add(dp[i][1], dp[i - 2][0]);
            add(dp[i][1], dp[i - 2][1]);
        }
    }

    bool f = true;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            f = false;
            break;
        }
    }

    if (!f) return cout << 0, 0;

    int ans = 0; add(ans, dp[n][0]); add(ans, dp[n][1]);
    cout << ans;
    return 0;
}
