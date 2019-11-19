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

const int MAXN = 100005;
const ll oo = 1000000000000000LL;

int N;
vector<int> G[MAXN];
int C[4][MAXN];

int nodes[MAXN], M;

ll dp[MAXN][4][4];
int tr[MAXN][4][4];
int ans[MAXN];

int main() {
    scanf("%d", &N);
    REP(j, 3) REP(i, N) {
        scanf("%d", &C[j+1][i]);
    }

    REP(i, N-1) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int cur = -1;
    int prev = -1;
    REP(i, N) {
        if (G[i].size() == 1) {
            cur = i;
            break;
        }
    }

    nodes[M++] = cur;
    REP(i, N-1) {
        int cnt = 0;
        int next = -1;
        for (int v : G[cur]) {
            if (v != prev) {
                cnt++;
                next = v;
            }
        }
        if (cnt != 1) {
            cout << -1 << endl;
            return 0;
        }

        nodes[M++] = next;
        prev = cur;
        cur = next;
    }

    FORD(i, N-1, 0) REP(prev1, 4) REP(prev2, 4) {
        dp[i][prev1][prev2] = oo;
        int n = nodes[i];
        FOR(cur, 1, 3) {
            if (cur != prev1 && cur != prev2) {
                ll x = C[cur][n] + dp[i+1][cur][prev1];
                if (x < dp[i][prev1][prev2]) {
                    dp[i][prev1][prev2] = x;
                    tr[i][prev1][prev2] = cur;
                }
            }
        }
    }

    if (dp[0][0][0] == oo) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[0][0][0] << endl;

    int prev1 = 0, prev2 = 0;
    REP(i, N) {
        int n = nodes[i];
        int cur = tr[i][prev1][prev2];
        ans[n] = cur;
        prev2 = prev1;
        prev1 = cur;
    }

    REP(i, N) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}
