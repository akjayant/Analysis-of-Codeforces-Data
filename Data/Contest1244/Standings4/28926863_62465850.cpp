#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b, c, d, k;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		int t1 = ceil(a * 1.0 / c), t2 = ceil(b * 1.0 / d);
		if (t1 + t2 > k)
			printf("-1\n");
		else
			printf("%d %d\n", t1, t2);
	}
}