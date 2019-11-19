#include <cstdio>
int main()
{
//	freopen("A.in", "r", stdin);
//	freopen("A.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--)
	{
		int a, b, c, d, k;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int x=(a-1)/c+1, y=(b-1)/d+1;
		if (x+y>k) puts("-1");
		else printf("%d %d\n", x, y);
	}
	return 0;
}