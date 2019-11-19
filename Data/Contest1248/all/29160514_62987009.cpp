#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector <int>
#define vl vector <ll>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define plld(x) printf("%lld",x)
#define pds(x) printf("%d ",x)
#define pllds(x) printf("%lld ",x)
#define pdn(x) printf("%d\n",x)
#define plldn(x) printf("%lld\n",x)
#define INF 2e9
#define INFLL 4e18
using namespace std;
ll powmod(ll base,ll exponent,ll mod){ // with mod < 1e9
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
const int upperlimit = 1e6+1;
const int mod = 1e9+7;
ll fib[upperlimit];
int main() {
	fib[0]=1;
	fib[1]=1;
	for(int i = 2; i < upperlimit; i++){
		fib[i]=fib[i-1]+fib[i-2];
		fib[i]%=mod;
	}
	int n,m;
	sd(n);sd(m);
	ll ans=fib[n];ans+=fib[m];ans--;
	ans*=2;ans%=mod;
	plld(ans);
	return 0;
}