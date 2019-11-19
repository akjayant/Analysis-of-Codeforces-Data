#include<bits/stdc++.h>
#define maxn 100005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long

using namespace std;

inline ll read(){
    ll x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

int main(){
	ll T=read();
	while(T--){
		ll n=read(),o1=0,e1=0,o2=0,e2=0;
		for(ll i=1;i<=n;i++){
			ll x=read();
			if(x%2) o1++; else e1++; 
		}
		ll m=read();
		for(ll i=1;i<=m;i++){
			ll x=read();
			if(x%2) o2++; else e2++;
		}
		ll ans=o1*o2+e1*e2;
		cout<<ans<<endl;
	}
	return 0;
}
