#include<bits/stdc++.h>
#define INF 0x7fffffff
#define pi acos(-1,0)
#define e 2.718281828459
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll const mod=1000000007;
ll fac[100005],inv[100005],f[100005];
ll mul(ll n,ll b){
	ll res=1;
	while(n){
		if(n&1){
			res=(res*b)%mod;
		}
		b=(b*b)%mod;
		n>>=1;
	}
	return res;
}
ll C(int n,int m){
	return (fac[n]*inv[m]%mod)*inv[n-m]%mod;
}
int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    ll maxn=max(n,m);
    fac[0]=1;fac[1]=1;
	ll ans=0;
	for(int i=2;i<=maxn;i++){
		fac[i]=fac[i-1]*i%mod;
	}
    inv[maxn]=mul(mod-2,fac[maxn]);
    for(int i=maxn-1;i>=0;i--){
    	inv[i]=inv[i+1]*(i+1)%mod;
	}
    for(int i=1;i<=n;i++){
        ans=ans+C(n-i,i)%mod;
        ans%=mod;
    }
    for(int i=1;i<=m;i++){
        ans=ans+C(m-i,i)%mod;
        ans%=mod;
    }
    ans=(ans*2%mod+2)%mod;
	printf("%lld\n",ans);
    return 0;
}