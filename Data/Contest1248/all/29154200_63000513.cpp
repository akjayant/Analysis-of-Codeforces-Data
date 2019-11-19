#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=1e9+7;
const ll maxn=5e5+5;
ll fac[maxn],inv[maxn];
ll ksc(ll a,ll b,ll p){
    ll tmp=a*b-(ll)((long double)a/p*b+0.5)*p;
    return tmp<0?tmp+p:tmp;
}
ll ksm(ll a,ll b,ll p){
	ll ans=1;
	for(;b;b>>=1,a=ksc(a,a,p)){
		if(b&1) ans=ksc(ans,a,p);
	}
	return ans;
}
ll C(ll n,ll m){
	if(n<m) return 0;
	else return	ksc(fac[n],ksc(inv[m],inv[n-m],p),p);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll ans=0;
	fac[0]=1;
	for(ll i=1;i<=5e5;++i)
		fac[i]=fac[i-1]*i%p;
	inv[500000]=ksm(fac[500000],p-2,p);
	for(ll i=5e5-1;i>=0;--i){
		inv[i]=inv[i+1]*(i+1)%p; 
	}
	for(ll i=1;i<=n/2;++i){
		ans=(ans+ksc(2ll,C(n-i*2+i+1-1,i),p)%p)%p;
	}
	for(ll i=1;i<=m/2;++i){
		ans=(ans+ksc(2ll,C(m-i*2+i+1-1,i),p)%p)%p;
	}
	cout<<(ans+2)%p<<'\n';
	
	return 0;
}