#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int nxt[10005][10];
int hsh (int x, int y) {
    return (x - 1) * 10 + y;
}
int m[105][105];
int ladder[100005];
double memo[100005];

double dp (int x) {
    if (memo[x] != -1) return memo[x];
    // cout << x << endl;
    if (x == 1) return memo[x] = 0;
    memo[x] = 0;
    int cnt = 0;
    for (int i = 1; i <= 6; ++i) {
        int v = nxt[x][i];
        if (v == -1) {
            cnt++;
            continue;
        }
        if (ladder[v]) memo[x] += (1.0/6) * (min(dp(ladder[v]), dp(v)));
        else memo[x] += (1.0/6) * (dp(v));
        // cout << x << " " << (1.0/6) * (dp(v) + 1) << endl;
    }
    memo[x] = (1 + memo[x]) / (1.0 - ((cnt * 1.0) / 6.0));
    return memo[x];
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 200; ++i) memo[i] = -1;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (i % 2 == 1) {
                if (j > 1) nxt[hsh(i, j)][1] = (hsh(i, j - 1));
                if (j == 1 && i != 1) nxt[hsh(i, j)][1] = (hsh(i - 1, j));
            } else {
                if (j + 1 <= 10) nxt[hsh(i, j)][1] = (hsh(i, j + 1));
                if (j == 10) nxt[hsh(i, j)][1] = (hsh(i - 1, j));
            }
            cin >> m[i][j];
            if (m[i][j]) ladder[hsh(i, j)] = (hsh(i - m[i][j], j));
        }
    }
    nxt[hsh(1, 1)][1] = -1;
    for (int i = 2; i <= 6; ++i)
        for (int j = 1; j <= 100; ++j)
            nxt[j][i] = (nxt[j][i-1] == -1 ? -1 : nxt[nxt[j][i-1]][1]);
    // for (int i = 1; i <= 10; ++i)
    //     for (int j = 1; j <= 10; ++j)
    //         cout << nxt[hsh(i, j)][3] << (j == 10 ? '\n' : ' ');
    cout << fixed << setprecision(10) << dp(hsh(10, 1)) << endl;
}
 