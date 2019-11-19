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
int arr[upperlimit];
int main() {
	int n;
	sd(n);
	int sum=0,sum1=0;
	for(int i = 1; i <= n; i++){
		sd(arr[i]);sum+=arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i = 1; 2*i <= n; i++) sum1+=arr[i];
	ll ans=sum1*1LL*sum1;
	sum-=sum1;
	ans+=sum*1LL*sum;
	plld(ans);
	return 0;
}