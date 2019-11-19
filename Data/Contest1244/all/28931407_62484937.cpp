#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long LL;

LL n, p, d, w;

int main(){
	scanf("%lld %lld %lld %lld", &n, &p, &w, &d);
	LL mx = p / w;
	LL x = -1, y = -1;
	bool ok = 0;
	for(LL i = mx; i >= mx - 10000000; --i){
		if((p - i * w) % d == 0){
			x = i;
			y = (p - i * w) / d;
		}
		if(x >= 0 && y >= 0 && n - x - y >= 0){
			ok = 1;
			break;
		}
	}
	if(ok) printf("%lld %lld %lld\n", x, y, n - x - y);
	else puts("-1");
}