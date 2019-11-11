#include <cstdio>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))

typedef long long ll;
ll read()
{
	ll ret = 0, t = 1; char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

ll gcd(ll a, ll b)
{
	if (b) return gcd(b, a % b);
	return a;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
	#endif
	int T = read();
	while (T--)
	{
		ll a = read(), b = read();
		puts(gcd(a,b) == 1 ? "Finite" : "Infinite");
	}
	return 0;
}