#include <bits/stdc++.h>
using namespace std;

long long Exgcd(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long t = Exgcd(b, a % b, y, x);
	y -= a / b * x;
	return t;
}

int main()
{
	long long n, p, w, d;
	scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
	long long x, y;
	long long gcd = Exgcd(w, d, x, y);
	if (p % gcd)
	{
		printf("-1\n");
		return 0;
	}
	long long k = w / gcd;
	y = (y % k) * ((p / gcd) % k);
	y = (y % k + k) % k;
	x = (p - y * d) / w;
	if (x >= 0 && x + y <= n && y >= 0)
	{
		printf("%lld %lld %lld\n", x, y, n - x - y);
		return 0;
	}
	gcd = Exgcd(w, d, x, y);
	k = d / gcd;
	x = (x % k) * ((p / gcd) % k);
	x = (x % k + k) % k;
	y = (p - x * w) / d;
	if (y >= 0 && x + y <= n)
	{
		printf("%lld %lld %lld\n", x, y, n - x - y);
		return 0;
	}
	printf("-1\n");
	return 0;
}