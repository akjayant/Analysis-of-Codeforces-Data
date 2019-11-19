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
int a[MAXN];
ll sum;
int main()
{
	int n;
	scanf("%d", &n);
	int minn = inf;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), sum += a[i];
	ll y = 0;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n / 2; i++)
		y += a[i];
	sum -= y;
	printf("%lld\n", sum * sum + y * y);
	return 0;
}