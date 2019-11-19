#include<bits/stdc++.h>
#define ll long long
const ll N=1e6+6;
const ll mod=1e9+7;
using namespace std;
ll read(ll &x){
	ll dat=0,oko=1;char chc=getchar();
	while(chc<'0'||chc>'9'){if(chc=='-')oko=-1;chc=getchar();}
	while(chc>='0'&&chc<='9'){dat=dat*10+chc-'0';chc=getchar();}
	x=dat*oko;return x;
}ll n,m,f[N];
int main(){
	f[1]=2,f[2]=4;
	read(n),read(m);
	for(ll i=3;i<=max(n,m);i++){
		f[i]=(f[i-1]+f[i-2])%mod;	
	}printf("%lld\n",(f[n]+f[m]-f[1]+mod)%mod);
	return 0;
}
