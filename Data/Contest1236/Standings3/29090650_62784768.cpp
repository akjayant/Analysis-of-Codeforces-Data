#include <bits/stdc++.h>

using namespace std;

int t, a, b, c;

int main()
{
	for(scanf("%d", &t); t--;)
	{
		scanf("%d %d %d", &a, &b, &c);
		int x = min(b, c / 2);
		b -= x;
		int y = min(a, b / 2);
		printf("%d\n", 3 * x + 3 * y);
	}
}