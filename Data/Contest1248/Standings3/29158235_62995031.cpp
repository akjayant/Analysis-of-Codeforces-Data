#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5, MOD = 1e9 + 7;

int readInt ()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
int a[555][555];
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
int f[N + 1], dp[N + 1];
main() {
    int n = readInt(), m = readInt();
    if (n > m) {
        swap(n, m);
    }
    f[1] = 2;
    f[2] = 4;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= MOD;
    }
    dp[1] = f[n];
    dp[2] = f[n] + 2;
    dp[3] = f[n] + 4;
    for (int i = 4; i <= m; i++) {
        dp[i] = 2 * dp[i - 1] - dp[i - 3];
        dp[i] += MOD;
        dp[i] %= MOD;
    }
    cout << dp[m] << "\n";
//    int tot = n * m;
//    int ans = 0;
//    for (int i = 0; i < (1 << tot); i++) {
//        int x = 1, y = 1;
//        for (int j = 0; j < tot; j++) {
//            if ((i & (1 << j))) {
//                a[x][y] = 1;
//            } else {
//                a[x][y] = 0;
//            }
//            y++;
//            if (y > m) {
//                y = 1;
//                x++;
//            }
//        }
//        bool ok = true;
//        for (int i2 = 1; i2 <= n; i2++) {
//            for (int j2 = 1; j2 <= m; j2++) {
//                int cnt = 0;
//                for (int k = 1; k <= 4; k++) {
//                    int lx = i2 + dx[k];
//                    int ly = j2 + dy[k];
//                    if (lx >= 1 && lx <= n && ly >= 1 && ly <= m && a[i2][j2] == a[lx][ly]) {
//                        ++cnt;
//                    }
//                }
//                if (cnt > 1) {
//                    ok = false;
//                }
//            }
//        }
//        if (ok) {
//            ++ans;
//        }
//    }
//    cout << ans;
}
/// 2 4 6 10 16 26 42
/**
2
4 6 8 12 18 28 44 70 112
3
6 8 10 14 20
4
10 12 14 18
5
16 18 20
6
26
**/
