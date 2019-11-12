#include<cstdio>
typedef long long ll;
const ll mod=1e9+7;
ll pw(ll a,int b){
	ll re=1;
	for(;b;a=a*a%mod,b>>=1)
		if(b&1) re=re*a%mod;
	return re;
}
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	printf("%lld",pw((pw(2,m)-1+mod)%mod,n));
	return 0;
}