#include <cstdio>

int gcd (int a, int b)
{
	return b==0?a:gcd(b,a%b);
}

int main (void)
{
	int t, a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &a, &b);
		printf("%s\n", (gcd(a,b)==1)?"Finite":"Infinite");
	}
	return 0;
}