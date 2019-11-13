#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll n,m;

ll quickpow(ll a,ll b){
	ll c=1;
	while(b){
		if(b&1)	c=c*a%MOD;
		a=a*a%MOD;b>>=1; 
	}
	return c;
}
void solve(){
	scanf("%lld %lld",&n,&m);
	printf("%lld\n",quickpow((quickpow(2,m)-1+MOD)%MOD,n));
}
int main(){
	solve();
	return 0;
}