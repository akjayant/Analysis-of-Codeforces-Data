#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	
	ll f[50][2][2], A, B;

	ll dfs(const int len, const int ca, const int cb)
	{
		if (len == -1)
			return 1;
		ll &ans = f[len][ca][cb];
		if (ans != -1)
			return ans;
		ans = 0;
		int a = (A >> len) & 1;
		int b = (B >> len) & 1;
		if (!ca || a)
			ans += dfs(len - 1, ca & (a == 1), cb & (b == 0));
		if (!cb || b)
			ans += dfs(len - 1, ca & (a == 0), cb & (b == 1));
		ans += dfs(len - 1, ca & (a == 0), cb & (b == 0));
		return ans;
	}

	ll solve(const ll a, const ll b)
	{
		if (a < 0 || b < 0)
			return 0;
		A = a, B = b;
		memset(f, -1, sizeof(f));
		return dfs(31, 1, 1);
	}
	
	void work()
	{
		int T;
		ll L, R;
		scanf("%d", &T);
		while (T--)
		{
			scanf("%lld%lld", &L, &R);
			printf("%lld\n", solve(R, R) - solve(L - 1, R) * 2 + solve(L - 1, L - 1));
		}
	}
}

int main()
{
	TYC::work();
	return 0;
}