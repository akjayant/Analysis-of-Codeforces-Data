#include <cstdio>
#include <algorithm>

const int MAX_W = 1e5 + 5;

long long n, p, d, w;
bool chk[MAX_W];

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
	long long y = std::min(n, p / d);
	long long tmp = (p - d * y) % w;
	while (tmp != 0 && !chk[tmp])
	{
		chk[tmp] = true;
		tmp = (p - d * (--y)) % w;
	}
	if (tmp != 0)
	{
		printf("-1\n");
		return 0;
	}
	long long x = (p - d * y) / w;
	long long k = lcm(w, d);
	long long step = k / d - k / w;
	//printf("step %lld\n", step);
	long long cnt = std::max((long long)0, (x + y - n + step - 1) / step);
	//printf("cnt %lld\n", cnt);
	x += cnt * (k / w);
	y -= cnt * (k / d);
	if (x >= 0 && y >= 0 && x + y <= p)
		printf("%lld %lld %lld\n", x, y, n - y - x);
	else
		printf("-1\n");
	return 0;
}
