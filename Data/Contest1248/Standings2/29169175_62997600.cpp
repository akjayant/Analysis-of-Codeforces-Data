#include<bits/stdc++.h>
#define maxn 100005
#define maxm 500005
#define inf 0x7fffffff
#define mod 1000000007
#define ll long long

using namespace std;

inline ll read(){
    ll x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

int main(){
	ll n=read(),m=read(),s1=2,s2=0;
	for(ll i=1;i<=n;i++){ll t=s2;s2=s1,s1=(s1+t)%mod;}
	ll ans=s1;s1=2,s2=0;
	for(ll i=2;i<=m;i++){
		ans=(ans+s1)%mod;
		ll t=s2;s2=s1,s1=(s1+t)%mod;
	} 
	cout<<ans<<endl;
	return 0;
}
