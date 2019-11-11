#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int t, n, a, b, c, dp[N][N][N], trace[N][N][N];
string s;

bool winnable (int x, int y) {
    if (x == 0 && y == 1) return true;
    if (x == 1 && y == 2) return true;
    if (x == 2 && y == 0) return true;
    return false;
}

int change (char c1) {
    if (c1 == 'R') return 0;
    if (c1 == 'S') return 1;
    return 2;
}

//0: rock
//1: scissors
//2: paper

void doTrace (int pos, int curA, int curB) {
    if (pos == 0) return;
    int cur = trace[pos][curA][curB];
    doTrace(pos - 1, curA - (cur == 0), curB - (cur == 2));
    if (cur == 0) cout << "R";
    else if (cur == 1) cout << "S";
    else cout << "P";
}

void solve(){
    cin >> n >> a >> b >> c >> s;
    memset(dp, -0x3f, sizeof(dp)); dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int rock = 0; rock <= a; rock++) {
            for (int paper = 0; paper <= b; paper++) {
                int scissors = i - (rock + paper);
                if (rock < a) {
                    if (dp[i + 1][rock + 1][paper] < dp[i][rock][paper] + winnable(0, change(s[i]))) {
                        dp[i + 1][rock + 1][paper] = dp[i][rock][paper] + winnable(0, change(s[i]));
                        trace[i + 1][rock + 1][paper] = 0;
                    }
                }

                if (paper < b) {
                    if (dp[i + 1][rock][paper + 1] < dp[i][rock][paper] + winnable(2, change(s[i]))) {
                        dp[i + 1][rock][paper + 1] = dp[i][rock][paper] + winnable(2, change(s[i]));
                        trace[i + 1][rock][paper + 1] = 2;
                    }
                }

                if (scissors < c) {
                    if (dp[i + 1][rock][paper] < dp[i][rock][paper] + winnable(1, change(s[i]))) {
                        dp[i + 1][rock][paper] = dp[i][rock][paper] + winnable(1, change(s[i]));
                        trace[i + 1][rock][paper] = 1;
                    }
                }
            }
        }
    }

    if (dp[n][a][b] < (n + 1) / 2) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    doTrace(n, a, b);
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
