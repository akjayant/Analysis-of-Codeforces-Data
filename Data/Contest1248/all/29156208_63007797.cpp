#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

ll n,m;
const int N=1e5+10;
ll mod=1e9+7;
ll ans;
ll now=0;
ll f[N];
 
int main(){
	scanf("%lld%lld",&n,&m);
	f[1]=0;f[2]=1;
	for(int i=3;i<=100000;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	ans=2;
//	for(int i=1;i<=10;i++){
//		printf("%lld ",f[i]);
//	}
	for(int i=1;i<=n;i++){
		ans=(ans+2*f[i])%mod;
	}
	for(int i=1;i<=m;i++){
		ans=(ans+2*f[i])%mod;
	}
	printf("%lld\n",ans);
	return 0;
} 