#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll f[maxn];
ll mod=1e9+7;
void init(){
	f[0]=f[1]=1;
	for(int i=2;i<maxn;i++){
		f[i]=f[i-1]+f[i-2];
		f[i]%=mod;
	}
}
ll pow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1)ans*=x;
		x*=x;
		ans%=mod;
		x%=mod;
		y>>=1;
	}
	return ans;
}
int main(){
	init();
	ll n,m;
	cin>>n>>m;
	ll ans=f[n]+f[m]-1;
	if(ans<0){
		ans+=mod;
	}
	ans%=mod;
	cout<<(ans*2%mod)<<endl; 
}
//-3 -15 0 1 12 -15 19
//