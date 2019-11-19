#include <vector>
#include <algorithm>
#define i(a) scanf("%lld",&a)
#define rep(a,b,c) for(long long a=b;a<c;a++)
typedef long long ll;
using namespace std;
struct mat {
	ll a;
	ll b;
	ll c;
	ll d;
};
ll p = 1000000007;
ll n, m;
mat p2(mat mt) {
	ll a = mt.a;
	ll b = mt.b;
	ll c = mt.c;
	ll d = mt.d;
	return {(a*a+b*c)%p,(a*b+b*d)%p,(c*a+d*c)%p,(c*b+d*d)%p};
}
mat mul1(mat mt) {
	ll a = mt.a;
	ll b = mt.b;
	ll c = mt.c;
	ll d = mt.d;
	return { (a + b) % p,a,a,b };
}
ll f(ll x) {
	mat res = { 1,1,1,0 };
	bool first=true;
	for (int i = 17; i >= 0; i--) {
		if (x & (1 << i)) {
			if (first) {
				first = false;
			}
			else {
				res = p2(res);
				res = mul1(res);
			}
		}
		else {
			if (!first) {
				res = p2(res);
			}
		}
	}
	return res.a;
}
int main() {
	i(n); i(m);
	printf("%lld", 2 * (f(n) + f(m) - 1) % p);
}