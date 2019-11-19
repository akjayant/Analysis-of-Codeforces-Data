#include <bits/stdc++.h>
#define rep(i, a, b) for(int i(a), i##_ORZ(b); i <= i##_ORZ; i++)
#define drep(i, a, b) for(int i(a), i##_ORZ(b); i >= i##_ORZ; i--)
using namespace std;
const int maxn = 100010, mod = 1e9+7;
typedef long long ll;
ll fac[maxn], rfac[maxn], n, m;
ll Power(ll x, ll p) {
	ll res = 1;
	for(; p; p >>= 1, x = x * x % mod) if(p & 1) res = res * x % mod;
	return res;
}
ll C(ll x, ll y) {
	return fac[x] * rfac[y] % mod * rfac[x - y] % mod;
}
int main() {
	scanf("%lld%lld", &n, &m);
	if(n < m) swap(n, m);
	ll ans = 0;
	fac[0] = rfac[0] = 1;
	rep(i, 1, n) fac[i] = fac[i-1] * i % mod, rfac[i] = Power(fac[i], mod - 2);
	rep(i, 0, n / 2) ans = (ans + 2 * C(n - i, i) % mod) % mod;
	rep(i, 1, m / 2) ans = (ans + 2 * C(m - i, i) % mod) % mod;
	printf("%lld\n", ans);
	return 0;
}
