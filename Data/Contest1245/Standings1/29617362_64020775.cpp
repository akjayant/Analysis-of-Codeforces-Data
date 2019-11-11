#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 2;
char s[N];
int dp[N][26];

void add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    cin >> (s + 1);
    dp[1][s[1] - 'a'] = 1;
    int cw = 'w' - 'a';
    int cm = 'm' - 'a';
    int n = strlen(s + 1);
    for(int i = 1; i <= n; ++i) {
        if(s[i] == 'w' || s[i] == 'm') {
            cout << 0;
            return 0;
        }
    }
    for(int i = 2; i <= n; i++) {
        int c = s[i] - 'a';
        if(s[i] == 'n' || s[i] == 'u') {
            for(int j = 0; j < 26; j++) {
                if(j != s[i] - 'a') {
                    add(dp[i][c], dp[i - 1][j]);
                } else {
                    if(s[i] == 'n') add(dp[i][cw], dp[i - 1][j]);
                    else add(dp[i][cm], dp[i - 1][j]);
                    add(dp[i][c], dp[i - 1][j]);
                }
            }
        } else {
            for(int j = 0; j < 26; j++)
                add(dp[i][c], dp[i - 1][j]);
        }
    }

    int sl = 0;
    for(int j = 0; j < 26; j++) {
        add(sl, dp[n][j]);
    }
    cout << sl;
}

