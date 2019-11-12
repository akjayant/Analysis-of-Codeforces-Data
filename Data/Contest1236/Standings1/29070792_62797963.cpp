#include<bits/stdc++.h>
#define ll long long
#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%I64d",&x)
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=3e2+5;
const int mod=1e9+7; 
int n;
int m;
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*1ll*a%mod;
		a=a*1ll*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
//	freopen("in.txt","r",stdin);
	scan(n);scan(m);
	ll ans=qpow((-1+qpow(2,m)+mod)%mod,n);
	cout<<ans<<"\n";
	return 0;
}