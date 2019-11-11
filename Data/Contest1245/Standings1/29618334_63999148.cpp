#include <cstdio>
#include <algorithm>

int t, a, b;

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &a, &b);
		printf("%s\n", (gcd(a, b) != 1 ? "Infinite" : "Finite"));
	}
	return 0;
}
