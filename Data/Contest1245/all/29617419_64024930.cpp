#include <bits/stdc++.h>
using i64 = long long;

i64 l, r;
i64 memo[61][2][2][2];
i64 rec(int d, bool a, bool b, bool c) {
    if (d < 0) return 1;
    if (memo[d][a][b][c] >= 0) return memo[d][a][b][c];
    i64 ret = 0;
    int dl = (l >> d) & 1, dr = (r >> d) & 1;

    if ((b || dl == 0) && (c || dr == 1)) {
        ret += rec(d - 1, true, b, c);
    }

    if (a) {
        ret += rec(d - 1, true, b || dl == 0, c || dr == 1);
    }

    if (b || dl == 0) {
        ret += rec(d - 1, a, b, c || dr == 1);
    }

    return memo[d][a][b][c] = ret;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> l >> r;
        for (int i = 0; i < 61; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) {
            memo[i][j][k][0] = memo[i][j][k][1] = -1;
        }
        std::cout << rec(60, false, false, false) * 2 - (l == 0 ? 1 : 0) << std::endl;
    }

    return 0;
}
