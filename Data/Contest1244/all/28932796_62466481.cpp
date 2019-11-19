#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int t, a, b, c, d, e;
int main()
{
	scanf("%d", &t);
	for (; t--; )
	{
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		int x = (a + c - 1) / c, y = (b + d - 1) / d;
		if (x + y > e)
			puts("-1");
		else
			printf("%d %d\n", x, y);
	}
}