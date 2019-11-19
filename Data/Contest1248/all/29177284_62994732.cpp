
#include <bits/stdc++.h>
using namespace std;
/*    freopen("k.in", "r", stdin);
    freopen("k.out", "w", stdout); */
//clock_t c1 = clock();
//std::cerr << "Time:" << clock() - c1 <<"ms" << std::endl;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define de(a) cout << #a << " = " << a << endl
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PLL;
typedef vector<int, int> VII;
#define inf 0x3f3f3f3f
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAXN = 2e5 + 7;
const ll MAXM = 5e6 + 7;
const ll MOD = 1e9 + 7;
const double eps = 1e-6;
const double pi = acos(-1.0);
ll dp[MAXN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int maxx = max(n, m);
	dp[1] = 2, dp[2] = 4;
	for (int i = 3; i <= maxx; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= MOD;
	}
	printf("%lld\n", ((dp[n] + dp[m] - 2) % MOD + MOD) % MOD);
	return 0;
}