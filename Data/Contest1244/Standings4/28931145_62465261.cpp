#include <bits/stdc++.h>
#define ll long long
#define sc scanf
#define pr printf
using namespace std;
int main()
{
	int T;
	sc("%d", &T);
	while (T--)
	{
		int a, b, c, d, k;
		sc("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int ans1 = ceil((double)a / c);
		int ans2 = ceil((double)b / d);
		if (ans1 + ans2 > k)
			puts("-1");
		else
			pr("%d %d\n", ans1, k - ans1);
	}
}