#include <bits/stdc++.h>

using namespace std;

int t, l, r;
long long dp[65][2][2][2][2];
string a, b;

void add (long long &x, long long y) {
    x += y;
}

string toBinary (int x) {
    string ans = "";
    while (x > 0) {
        int rem = x % 2;
        x /= 2;
        ans += (char)(rem + 48);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    cin >> l >> r;
    a = toBinary(l); b = toBinary(r);
    while (a.length() < b.length()) a = "0" + a;
    memset(dp, 0, sizeof(dp));
    dp[0][1][1][1][1] = 1;
    for (int i = 0; i < a.length(); i++) {
        for (int l1 = 0; l1 < 2; l1++) {
            for (int h1 = 0; h1 < 2; h1++) {
                for (int l2 = 0; l2 < 2; l2++) {
                    for (int h2 = 0; h2 < 2; h2++) {
                        //cout << i << " " << l1 << " " << h1 << " " << l2 << " " << h2 << " " << dp[i][l1][h1][l2][h2] << "\n";
                        int limlow1 = 0, limhigh1 = 1, limlow2 = 0, limhigh2 = 1;
                        if (l1) limlow1 = a[i] - '0';
                        if (h1) limhigh1 = b[i] - '0';
                        if (l2) limlow2 = a[i] - '0';
                        if (h2) limhigh2 = b[i] - '0';

                        for (int nxt = 0; nxt < 2; nxt++) {
                            int cnxt = nxt ^ 1;
                            bool ok = true;
                            if (nxt < limlow1 || nxt > limhigh1 || cnxt < limlow2 || cnxt > limhigh2) ok = false;
                            if (ok) {
                                int nl1 = (l1 && nxt == a[i] - '0');
                                int nh1 = (h1 && nxt == b[i] - '0');
                                int nl2 = (l2 && cnxt == a[i] - '0');
                                int nh2 = (h2 && cnxt == b[i] - '0');
                                add(dp[i + 1][nl1][nh1][nl2][nh2], dp[i][l1][h1][l2][h2]);
                            }

                            if (!nxt) {
                                cnxt = nxt;
                                ok = true;
                                if (nxt < limlow1 || nxt > limhigh1 || cnxt < limlow2 || cnxt > limhigh2) ok = false;
                                if (ok) {
                                    int nl1 = (l1 && nxt == a[i] - '0');
                                    int nh1 = (h1 && nxt == b[i] - '0');
                                    int nl2 = (l2 && cnxt == a[i] - '0');
                                    int nh2 = (h2 && cnxt == b[i] - '0');
                                    add(dp[i + 1][nl1][nh1][nl2][nh2], dp[i][l1][h1][l2][h2]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    add(ans, dp[a.length()][i][j][k][l]);
                }
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
