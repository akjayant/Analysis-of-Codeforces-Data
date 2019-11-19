/*
 * (c) fushar (Ashar Fuadi)
*/

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, _n = n; i < _n; i++)
#define FOR(i, a, b) for (int i = a, _b = b; i <= _b; i++)
#define FORD(i, b, a) for (int i = b, _a = a; i >= _a; i--)
#define RESET(c, v) memset(c, v, sizeof c)

using namespace std;
using ll = long long;

/***********************************************************/

int G[15][15];
int X[105], Y[105];
int D[15][15];

double dp[105];

int main() {
    REP(i, 10) REP(j, 10) cin >> G[i][j];

    int dir = 1;
    int i = 9, j = 0;
    REP(n, 100) {
        X[n] = i;
        Y[n] = j;
        D[i][j] = n;

        j += dir;
        if (j == 10) {
            j--;
            i--;
            dir = -1;
        } else if (j == -1) {
            j++;
            i--;
            dir = 1;
        }
    }

    dp[99] = 0;

    for (int i = 98; i >= 0; i--) {
        int same = 0;
        double diff = 0;

        for (int d = 1; d <= 6; d++) {
            int j = i+d;

            if (j > 99) {
                same++;
                continue;
            }

            double next = dp[j];
            int x = X[j];
            int y = Y[j];
            if (G[x][y]) {
                next = min(next, dp[D[x-G[x][y]][y]]);
            }

            diff += next;
        }
        dp[i] = (6 + diff) / (6 - same);
    }

    printf("%.10lf\n", dp[0]);
}
