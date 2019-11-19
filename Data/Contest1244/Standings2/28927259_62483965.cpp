#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,p,w,d;
ll f(ll a,ll m){
	return a*w+(m-a)*d;
}
ll bs(ll s){
	ll l=0,r=s;
	while(l<=r){
		ll m=l+r>>1;
		if(f(m,s)==p)return m;
		if(f(m,s)<p)l=m+1;
		else r=m-1;
	}
	return r;
}
int main(){
	cin>>n>>p>>w>>d;
	bool is=0;
	ll r=min(p/d,n),l=max(r-(w-d)*2,0ll);
	for(ll m=r;m>=l;m--){
		ll x=bs(m);
		if(f(x,m)==p){
			cout<<x<<' '<<m-x<<' '<<n-m;
			is=1;
			break;
		}
	}
	if(!is)cout<<"-1";
	return 0;
}