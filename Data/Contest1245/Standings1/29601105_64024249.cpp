#include <cstdlib>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 10;

struct coord {
    int r, c;
};

int board[N + 10][N + 10]; // flip board vertically compared to examples

coord END = {9, 0};

coord next(coord cur) {
    if (cur.r % 2 == 0) {
        if (cur.c < N - 1) return {cur.r, cur.c + 1};
        else return {cur.r + 1, cur.c};
    } else {
        if (cur.c > 0) return {cur.r, cur.c - 1};
        else return {cur.r + 1, cur.c};
    }
}

coord prev(coord cur) {
    if (cur.r % 2 == 0) {
        if (cur.c > 0) return {cur.r, cur.c - 1};
        else return {cur.r - 1, cur.c};
    } else {
        if (cur.c < N - 1) return {cur.r, cur.c + 1};
        else return {cur.r - 1, cur.c};
    }
}

long double dp[N + 10][N + 10];

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &board[N - i - 1][j]);
        }
    }

    dp[N - 1][0] = 0.0;
    coord cur = prev(END);
    while (true) {
        if (cur.r == N - 1) {
            coord nex = next(cur);
            long double sum_normal = 0.0;
            long double prob_fail = 0.0;
            for (int i = 0; i < 6; ++i) {
                if (nex.r >= N) {
                    prob_fail += 1.0 / 6.0;
                } else {
                    sum_normal += dp[nex.r][nex.c] / 6.0;
                }
                nex = next(nex);
            }

            dp[cur.r][cur.c] = (1 + sum_normal) / (1.0 - prob_fail);
        } else {
            coord nex = next(cur);
            double sum = 0.0;
            for (int i = 0; i < 6; ++i) {
                double choice1 = dp[nex.r][nex.c];
                double choice2 = dp[nex.r + board[nex.r][nex.c]][nex.c];
                sum += min(choice1, choice2);
                nex = next(nex);
            }

            dp[cur.r][cur.c] = 1.0 + sum / 6.0;
        }

        //printf("%d %d: %0.9Lf\n", cur.r, cur.c, dp[cur.r][cur.c]);

        if (cur.r == 0 && cur.c == 0) {
            break;
        } else {
            cur = prev(cur);
        }
    }

    printf("%0.12Lf\n", dp[0][0]);

    return 0;
}
