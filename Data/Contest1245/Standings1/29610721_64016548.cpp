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

int N;
char S[100005];
int dp[100005];

const int MOD = 1000000007;

int main() {
    scanf("%s", S);
    N = strlen(S);
    dp[N] = 1;

    for (int i = N-1; i >= 0; i--) {
        if (S[i] == 'm' || S[i] == 'w') {
            continue;
        }
        dp[i] = dp[i+1];
        if (i+1 < N && S[i] == 'u' && S[i+1] == 'u') {
            dp[i] = (dp[i] + dp[i+2]) % MOD;
        }
        if (i+1 < N && S[i] == 'n' && S[i+1] == 'n') {
            dp[i] = (dp[i] + dp[i+2]) % MOD;
        }
    }

    printf("%d\n", dp[0]);
}
