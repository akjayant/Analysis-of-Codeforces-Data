#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+5;
const ll mod=1e9+7;

ll qp(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;	
}

int main()
{
	ll n,m;
	scanf("%lld %lld",&n,&m);
	ll ans=qp(qp(2,m)-1,n);
	printf("%lld\n",ans);
    return 0;
}
