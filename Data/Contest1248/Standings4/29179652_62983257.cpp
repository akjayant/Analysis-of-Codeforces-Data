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

int a[100009];
int main()
{
	int n;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	if (n % 2 == 0)
	{
		ll k1=0, k2=0;
		for (int i = 1; i <= n/2; i++)
			k1 += a[i];
		for (int i = n / 2 + 1; i <= n; i++)
			k2 += a[i];
		ans = k1 * k1 + k2 * k2;
	}
	else
	{
		ll k1 = 0, k2 = 0;
		for (int i = 1; i <= n / 2; i++)
			k1 += a[i];
		for (int i = n / 2 + 1; i <= n; i++)
			k2 += a[i];
		ans = k1 * k1 + k2 * k2;
		k1 = 0;
		k2 = 0;
		for (int i = 1; i <= n / 2 + 1; i++)
			k1 += a[i];
		for (int i = n / 2 + 2; i <= n; i++)
			k2 += a[i];
		ans = max(ans, k1 * k1 + k2 * k2);
	}
	printf("%lld\n", ans);

	return 0;
}
