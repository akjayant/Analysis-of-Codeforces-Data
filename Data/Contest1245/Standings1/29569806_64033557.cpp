#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pLL;
typedef pair<LL, int> pLi;
typedef pair<int, LL> pil;;
typedef pair<int, int> pii;
typedef unsigned long long uLL;

#define fi first
#define se second
#define lson (rt<<1)
#define rson (rt<<1|1)
#define lowbit(x) x&(-x)
#define name2str(name) (#name)
#define bug printf("*********\n")
#define debug(x) cout<<#x"=["<<x<<"]" <<endl
#define FIN freopen("D://Code//in.txt","r",stdin)

const double eps = 1e-8;
const int mod = 1000000007;
const int maxn = 200000 + 7;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int t, l, r;
int num1[32], num2[32];
LL dp[32][2][2][2];

LL dfs(int pos, int limit1, int limit2, int ok) {
	if(pos == -1) return ok;
	if(dp[pos][limit1][limit2][ok] != -1) return dp[pos][limit1][limit2][ok];
	int up1 = limit1 ? num1[pos] : 1;
	int up2 = limit2 ? num2[pos] : 1;
	LL ans = 0;
	for(int i = 0; i <= up1; ++i) {
		for(int j = 0; j <= up2; ++j) {
			ans += dfs(pos - 1, limit1 && (i == up1), limit2 && (j == up2), (ok && (!(i & j))));
		}
	}
	dp[pos][limit1][limit2][ok] = ans;
	return ans;
}

LL solve(LL L, LL R) {
    memset(dp, -1, sizeof(dp));
	for(int i = 0; i <= 30; ++i) {
		num1[i] = L % 2, L >>= 1;
		num2[i] = R % 2, R >>= 1;
	}
	return dfs(30, 1, 1, 1);
}

int main() {
    scanf("%d", &t);
    while(t--) {
    	scanf("%d%d", &l, &r);
    	LL ans = solve(r, r) - solve(l-1, r) - solve(r, l-1) + solve(l-1, l-1);
    	printf("%lld\n", ans);
    }
    return 0;
}
