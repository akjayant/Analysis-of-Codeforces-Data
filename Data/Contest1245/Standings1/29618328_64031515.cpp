#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
#define cases(t) for (int cas = 1; cas <= int(t); ++cas)
typedef long long ll;
typedef double db;
using namespace std;

#ifdef NO_ONLINE_JUDGE
#define LOG(args...) do { cout << #args << " -> "; err(args); } while (0)
void err() { cout << endl; }
template<typename T, typename... Args> void err(T a, Args... args) { cout << a << ' '; err(args...); }
#else
#define LOG(...)
#endif

int bits1[40], bits2[40];
ll dp[40][2][2][2][2];
ll dfs(int x, int a, int b, int limit1, int limit2) {
    if (x < 0) return 1;
    if (~dp[x][a][b][limit1][limit2])	return dp[x][a][b][limit1][limit2];
    int up1 = limit1 ? bits1[x] : 1;
    int up2 = limit2 ? bits2[x] : 1;
    ll ret = 0;
    for (int i = 0; i <= up1; ++i) {
        for (int j = 0; j <= up2; ++j) {
            if (i & j)	continue;
            ret += dfs(x - 1, i, j, limit1 && i == bits1[x], limit2 && j == bits2[x]);
        }
    }
    return dp[x][a][b][limit1][limit2] = ret;
}
ll solve(int x1, int x2) {
    int cnt1 = -1;
    while (x1) {
        bits1[++cnt1] = x1 & 1;
        x1 >>= 1;
    }
    int cnt2 = -1;
    while (x2) {
        bits2[++cnt2] = x2 & 1;
        x2 >>= 1;
    }
    while (cnt1 > cnt2) {
        bits2[++cnt2] = 0;
    }
    while (cnt1 < cnt2) {
        bits1[++cnt1] = 0;
    }
    memset(dp, -1, sizeof dp);
    return dfs(cnt1, 0, 0, 1, 1);
}

int main() {
    int l, r, t;
    scanf("%d", &t);
    cases(t) {
        scanf("%d%d", &l, &r);
        if (l == 0) {
            printf("%lld\n", solve(r, r));
        } else {
            printf("%lld\n", solve(r, r) - solve(r, l - 1) - solve(l - 1, r) + solve(l - 1, l - 1));
        }
    }
    return 0;
}