#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<unordered_map>

#define ll long long
#define mt(a) memset(a,0,sizeof(a))
#define MAXI 2000000000
#define MAXLL 1e18+9
#define PAI pair<int,int>
#define EPS 1e-12
#define ls (rt << 1)
#define rs (rt << 1 | 1)


using namespace std;	

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m, ji1 = 0, ji2 = 0, ou1 = 0, ou2 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int k;
			scanf("%d", &k);
			if (k % 2 != 0)
				ji1++;
			else
				ou1++;
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			int k;
			scanf("%d", &k);
			if (k % 2 != 0)
				ji2++;
			else
				ou2++;
		}
		ll ans = 0;
		ans += 1ll * ji1 * ji2;
		ans += 1ll * ou1 * ou2;
		printf("%lld\n", ans);
	}
	return 0;
}