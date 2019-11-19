#include <map>
#include <set>
#include <cmath>
#include <ctime> 
#include <queue>
#include <stack>    
#include <bitset> 
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define pb push_back
#define MP std::make_pair
#define PII std::pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CL(a, b) memset(a, b, sizeof a)
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, r, l) for (int i = (r); i >= (l); -- i)
#define PE(x, a) for (int x = head[a]; x;x = edge[x].next)

typedef long long ll;

const ll HA = 1e9 + 7;
const int MAXN = 1e6 + 7;

int n, m;
ll f[MAXN][2], g[MAXN][2];

void solveCalc() {
    rep(i, 2, std::max(n, m) + 1) {
        f[i][1] = f[i - 1][0];
        f[i][0] = (f[i - 1][1] + f[i - 1][0]) % HA;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    f[1][0] = 2;
    solveCalc();
    ll ans = (f[m + 1][0] + f[n + 1][0] + HA - 2) % HA;
    printf("%lld\n", ans);
    return 0;
}