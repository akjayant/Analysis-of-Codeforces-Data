#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void exgcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0) { x = 1; y = 0; return; }
	exgcd(b, a % b, x, y);
	ll t = x; x = y, y = t - a / b * y;
}

int main()
{
    ll n, c, a, b;
    scanf("%lld%lld%lld%lld", &n, &c, &a, &b);
    int d = __gcd(a, b);
    if(c % d) return 0 * puts("-1");
    ll x, y;
    exgcd(b, a, y, x);
    ll d1 = b / d, d2 = a / d;
    y = (y % d2 * ((c / d) % d2) % d2 + d2 )% d2, x = (c - b * y ) / a;
    if(x < 0 || y < 0) return 0 * puts("-1");
    if(x + y > n) return 0 * puts("-1");
    printf("%lld %lld %lld\n", x, y, n - x - y);
    return 0;
}
