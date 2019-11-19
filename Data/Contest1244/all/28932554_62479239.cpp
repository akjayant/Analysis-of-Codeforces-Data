#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define str string
#define fi first
#define se second
#define pb push_back
#define SET(a, b) memset(a, b, sizeof(a))
#define eps 1e-6
#define pi atan(1) * 4
#define mod 1000000007
#define inf 1000000000
#define llinf 1000000000000000000
#define FOR(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define FORD(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
using namespace std;
string output;
ll lx, ly, ld;
void eea (ll a, ll b) {
	if (b == 0) {
		ly = 1; lx = 0; ld = a; return;
	}
	eea(b, a % b);
	ll ny = lx;
	ll nx = ly - (a / b) * lx;
	ly = ny; lx = nx;
	return;
}
ll fgcd (ll a, ll b) {
	if (b == 0) return a;
	else return fgcd(b, a % b);
}
int main () {
	ll n, k, p, f;
	ll mark;
	scanf("%lld %lld %lld %lld", &k, &mark, &p, &f);
    swap(p, f);
	ll d = f - p;
	eea(d, p);
	ll lcm = p * f / fgcd(p, f);
	ll dx = lcm / p, dy = lcm / f;
		ll r = mark % p, q = mark / p;
		
		ll rm = r % d;
		if (rm % ld != 0) {
            cout << -1 << endl;
            return 0;
		}
		ll x = rm / ld * -lx;
		ll y = (x * p + r) / d;
		x = q - x - y;
		//cout << "first: " << x << ' ' << y << endl;
		
		if (x < 0) {
			ll b = -x / dx + (-x % dx != 0);
			x += b * dx; y -= b * dy;
		} else if (x > 0) {
			ll b = x / dx;
			x -= b * dx; y += b * dy;
		}
		if (y < 0 || x + y > k) cout << -1 << endl;
		else cout << y << " " << x << " " << k - x - y << endl;
		//cout << x << ' ' << y << endl;
	// printf("%s\n", output.c_str());
	return 0;
}