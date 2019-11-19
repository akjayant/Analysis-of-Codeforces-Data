#include <cstdio>
#include <algorithm>

const int MAX_N = 1e5 + 5;

int q, a, b, c, d, k;

int main()
{
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int x = (a + c - 1) / c,
		    y = (b + d - 1) / d;
		if (x + y <= k)
			printf("%d %d\n", x, y);
		else
			printf("-1\n");
	}
	return 0;
}
