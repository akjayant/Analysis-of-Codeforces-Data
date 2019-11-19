#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100008;

int t, n, m;
int p, q;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		ll ans = 0, p1 = 0, p2 = 0, q1 = 0, q2 = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &p);
			if (p % 2) p1++;
			else p2++;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &q);
			if (q % 2) q1++;
			else q2++;
		}
		ans = p1 * q1 + p2 * q2;
		printf("%lld\n", ans);
	}
}