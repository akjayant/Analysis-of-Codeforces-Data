#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double db;

# define pi pair<int, int>
# define pb push_back

template <typename t> void Max(t &a, t b) { if(a < b) a = b; }
template <typename t> void Min(t &a, t b) { if(a > b) a = b; }
template <typename t>
inline void read(t &x) {
	x = 0; t f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar())
		if(c == '-') f = -1;
	for(;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	x *= f;
}

const int N = 0;

LL n, p, w, d, x, y;

LL exgcd(LL a, LL b, LL &x, LL &y) {
	LL d;
	if(!b) {
		d = a;
		x = 1, y = 0;
	} else {
		d = exgcd(b, a % b, x, y);
		LL t = x;
		x = y;
		y = t - (a / b) * y;
	}
	return d;
}
int main() {
	cin >> n >> p >> w >> d;
	LL gcd = exgcd(w, d, x, y);
	if(p % gcd) return 0 * printf("-1\n");
	LL A = w / gcd;
	LL B = d / gcd;
	x = x % B * ((p / gcd) % B);
	{
		x = (x % B + B) % B;
		y = (p - w * x) / d;
		if(n >= x + y && x >= 0 && y >= 0) {
			printf("%lld %lld %lld\n", x, y,  n - x - y);
			return 0;
		}
	}
	{
		y = (y % A + A) % A;
		x = (p - d * y) / w;
		if(n >= x + y && x >= 0 && y >= 0) {
			printf("%lld %lld %lld\n", x, y, n - x - y);
			return 0;
		}
	}
	printf("-1\n");
	// if(y < 0) {
	// 	LL del = abs(y);
	// 	LL bas = ceil(1.0 * del / A);
	// 	y += A * bas;
		
	// }
	return 0;
}
