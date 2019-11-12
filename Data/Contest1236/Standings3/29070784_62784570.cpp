#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int dp[N][N][N], t, a, b, c;

int main(){
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &c);
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    dp[i][j][k] = -1e9;
                }
            }
        }

        dp[a][b][c] = 0;
        for (int i = a; i >= 0; i--) {
            for (int j = b; j >= 0; j--) {
                for (int k = c; k >= 0; k--) {
                    if (i >= 1 && j >= 2) {
                        dp[i - 1][j - 2][k] = max(dp[i - 1][j - 2][k], dp[i][j][k] + 3);
                    }

                    if (j >= 1 && k >= 2) {
                        dp[i][j - 1][k - 2] = max(dp[i][j - 1][k - 2], dp[i][j][k] + 3);
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    ans = max(ans, dp[i][j][k]);
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
