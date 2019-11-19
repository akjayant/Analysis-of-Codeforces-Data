#pragma GCC optimize(2)
#include<functional>
#include<algorithm>
#include<iostream>
#include<cassert>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<stack>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep2(i,a,b) for(int i=a;i>=b;i--)
#define mst(t, v, n) memset(t, v, sizeof(decltype(*(t))) * (n))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
//const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int  INF = 0x3f3f3f3f;
const ll inf = 1ll << 62 - 1ll;
const int MAXN = 1e5 + 10;
const int N = 26;
ll a[MAXN], sum[MAXN];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef ONLINE_JUDGE
#else
	freopen("./std.in", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	sum[1] = 2;
	sum[2] = 4;
	if (n < m)
		swap(n, m);
	rep(i, 3, n)
	{
		sum[i] = (sum[i - 1] + sum[i - 2]) % mod;
	}
	ans = (sum[n] + sum[m] - 2) % mod;
	cout << ans << endl;
	return 0;
}
