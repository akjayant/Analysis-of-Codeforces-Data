#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))
#define mp make_pair

typedef long long ll;

const int N = 60;
ll n, now;

void read(ll& x)
{
	x = 0; bool fl = 0; char ch = getchar();
	while (!(ch >= '0' && ch <= '9')) fl |= (ch == '-'), ch = getchar();
	while ((ch >= '0' && ch <= '9')) x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (fl) x = -x;
}

ll gcd(ll x, ll y)
{
	return (!y) ? x : gcd(y, x % y);
}

int main()
{
	read(n); now = n;
	for (int i = 2; i <= 1000000; ++i)
	{
		bool fl = 0;
		while (!(n % i))
		{
			n /= i;
			fl = 1;
		}
		if (fl) now = gcd(now, i);
		if (n < i) break;
	}
	if (n != 1) now = gcd(now, n);
	printf("%I64d\n", now);
	return 0;
}