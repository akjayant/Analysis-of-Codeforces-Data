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

const int MAXN = 2e5 + 7;

int n, m;
int p[MAXN], q[MAXN];
ll c1[2], c2[2];

void solve() {
    CL(c1, 0);
    CL(c2, 0);

    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", p + i), c1[p[i] % 2]++;
    scanf("%d", &m);
    rep(j, 1, m) scanf("%d", q + j), c2[q[j] % 2] ++;
    ll ans = c1[0] * c2[0] + c1[1] * c2[1];
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}