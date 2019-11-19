#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+7;
int main()
{
	int t, n, m;
	scanf("%d", &t);
	while(t--)
	{
		ll ans = 0;
		int c1 = 0, c2 = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			c1 += (a&1);
			c2 += ((a&1)^1);
		}
		scanf("%d", &m);
		for(int i = 1; i <= m; i++)
		{
			int a;
			scanf("%d", &a);
			ans = ans+(a&1)*c1+((a&1)^1)*c2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
