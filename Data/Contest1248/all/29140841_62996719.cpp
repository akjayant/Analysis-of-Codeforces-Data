#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#include <time.h>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
#define RAND (rand()*rand())
#define MAX(x, y) ((x) > (y) ? (x):(y)) 
#define MIN(x, y) ((x) > (y) ? (y):(x))
#define ABS(x) ((x) > 0 ? ((x) : -(x)))
using namespace std;
const int MAXN = 1e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, K, Q;
ll dp[MAXN][2][2];

ll cal_dp(int pos, int ppre, int pre) {
	if (pos == 0) {
		return 1ll;
	}
	ll &ret = dp[pos][ppre][pre];
	if (ret != -1ll) return ret;
	ret = 0ll;
	if (ppre == pre) {
		ret =  cal_dp(pos - 1, pre, !pre);
	}
	else {
		ret = (ret + cal_dp(pos - 1, pre, !pre)) %MOD;
		ret = (ret + cal_dp(pos - 1, pre, pre)) % MOD;
	}
	return ret;
}

int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	memset(dp, -1, sizeof(dp));
	ll a = cal_dp(M, 0, 0);
	ll b = cal_dp(M, 1, 1);
	ll c = cal_dp(N, 0, 0);
	ll d = cal_dp(N, 1, 1);
	ll ans = (((a + b - 2ll + MOD) % MOD) + (c + d % MOD)) % MOD;
	printf("%lld", ans);
	return 0;
}