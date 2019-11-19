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
const int mod = 998244353;
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
	int n;
	cin >> n;
	rep(i, 1, n)cin >> a[i];
	sort(a + 1, a + 1 + n);
	sum[0] = 0;
	rep(i, 1, n)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	int t = n >> 1;
	ll a = sum[n] - sum[t];
	ll b = sum[t];
	ll k = a * a + b * b;
	cout << k << endl;
	return 0;
}
