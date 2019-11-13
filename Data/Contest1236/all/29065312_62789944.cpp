#include <bits/stdc++.h>
#define VI vector<int>
#define pb push_back
#define LL long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9+7;
LL fpow(LL a, LL e){
	LL  x = 1LL, y = a;
	while(e){
		if(e&1LL) x = (x*y)%mod;
		y = (y*y)%mod;
		e >>= 1LL;
	}
	return x;
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%lld\n", fpow((fpow(2,m)-1+mod)%mod, n));
	return 0;
}