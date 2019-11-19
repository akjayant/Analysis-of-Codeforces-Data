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
const int MAXN = 3e5 + 10;
const int N = 26;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef ONLINE_JUDGE
#else
	freopen("./std.in", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n, m,j1=0,o2=0;
		ll ans = 0;
		cin >> n;
		rep(i, 1, n)
		{
			int a;
			cin >> a;
			if (a % 2 == 0)
				o2++;
			else
				j1++;
		}
		cin >> m;
		rep(i, 1, m)
		{
			int a;
			cin >> a;
			if (a % 2 == 0)
				ans += o2;
			else
				ans += j1;
		}
		cout << ans << endl;
	}
	return 0;
}
