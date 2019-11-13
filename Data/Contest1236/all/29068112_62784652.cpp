/*
    Author: Nguyen Tan Bao
    Status:
    Idea:
*/

#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x

using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<II, int> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;

const ll MODBASE = 1000000007LL;
const int MAXN = 300010;
const int MAXM = 1010;
const int MAXK = 110;
const int MAXQ = 200010;

int dp[110][110][110];

int solve(int a, int b, int c) {
    if (dp[a][b][c] != -1) return dp[a][b][c];

    int res = 0;

    if (a >= 1 && b >= 2) {
        res = max(res, 3 + solve(a-1, b-2, c));
    }

    if (b >= 1 && c >= 2) {
        res = max(res, 3 + solve(a, b-1, c-2));
    }

    return dp[a][b][c] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    FOR(i,0,100) FOR(j,0,100) FOR(k,0,100) dp[i][j][k] = -1;
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << "\n";
    }
    return 0;
}
