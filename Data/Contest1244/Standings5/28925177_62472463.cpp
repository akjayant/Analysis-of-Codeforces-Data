#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, a, b, c, d, k;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int x, y;
		x = a / c + (a % c > 0);
		y = b / d + (b % d > 0);
		if (k - x >= y)
			printf("%d %d\n", x, k - x);
		else
			printf("-1\n");
	}
	return 0;
}