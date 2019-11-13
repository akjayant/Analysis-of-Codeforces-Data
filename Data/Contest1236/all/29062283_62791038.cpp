#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n,m;
ll qpow(ll a,ll n){
	ll ans=1;
	for(;n;n>>=1){
		if(n&1) ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	int t,i,j,k,a,b,c,ans;
	cin>>n>>m;
	ll tmp=(qpow(2,m)+mod-1)%mod;
	cout<<qpow(tmp,n)<<endl;
//(2^m-1)^n
	return 0;
}
