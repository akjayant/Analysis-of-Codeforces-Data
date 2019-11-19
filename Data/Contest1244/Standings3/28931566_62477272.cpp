#include<bits/stdc++.h>
#define rint register int
#define deb(x) cerr<<#x<<" = "<<(x)<<'\n';
//#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
typedef long long ll;
using pii = pair <ll,int>;

int main() {
	ll n, p, w, d;
	ll x, y, z;
	scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
	x = p / w, y = 0;
	for(int i=0; i<=1e6; i++){
		ll x1 = x - i;
		if(x1 < 0) break;
		ll p1 = p - x1 * w;
		ll y1 =  p1 / d;
		if(x1 + y1 > n || x1*w+y1*d != p) continue;
		printf("%lld %lld %lld\n", x1, y1, n-x1-y1);
		return 0;
	}
	puts("-1");
}
