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
const int upperlimit = 3e2+1;
const int mod = 1e9+7;
vi sets[upperlimit];
int main() {
	int n;
	sd(n);
	for(int i = 0; i < n; i++){
		if(i&1){
			for(int j = 1; j <= n; j++) sets[j].pb(j+(n*i));
		}
		else for(int j = 1; j <= n; j++) sets[j].pb(n*(i+1)-j+1);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n; j++) pds(sets[i][j]);
		printf("\n");
	}
	return 0;
}