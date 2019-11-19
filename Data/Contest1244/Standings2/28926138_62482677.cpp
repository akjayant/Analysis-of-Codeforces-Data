#include <cstdio>
typedef long long ll;
int main()
{
//	freopen("C.in", "r", stdin);
//	freopen("C.out", "w", stdout);
	ll n, p; ll w, d;
	scanf("%I64d%I64d%I64d%I64d", &n, &p, &w, &d);
	bool flag=0;
	for (ll y=0; y<=w; y++)
		if ((p-y*d)%w==0)
		{
			ll x=(p-y*d)/w;
			if (x>=0&&x+y<=n)
			{
				flag=1;
				printf("%I64d %I64d %I64d\n", x, y, n-x-y);
			}
			break;
		}
	if (!flag) puts("-1");
	return 0;
}