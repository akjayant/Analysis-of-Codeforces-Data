#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
const int M=2e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
		ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll c=qpow(2,b)-1;
	printf("%lld\n",qpow(c,a));
	return 0;
}
