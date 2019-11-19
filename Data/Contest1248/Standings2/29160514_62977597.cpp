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
int main() {
	int t;
	int o1,e1,o2,e2,inp;
	sd(t);
	while(t--){
		o1=0,o2=0,e1=0,e2=0;
		int n,m;
		sd(n);
		for(int i = 1; i <= n; i++){
			sd(inp);
			if(inp&1) o1++;
			else e1++;
		}
		sd(m);
		for(int i = 1; i <= m; i++){
			sd(inp);
			if(inp&1) o2++;
			else e2++;
		}
		ll ans=o1*1LL*o2;
		ans+=e1*1LL*e2;
		plldn(ans);
	}
	return 0;
}