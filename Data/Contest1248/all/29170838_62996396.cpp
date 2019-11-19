#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define maxn 100111
#define ll long long 
#define ull unsigned long long 
const ll mod = 1e9+7;

ll qpow(ll a,ll n){
	ll ret = 1LL;
	while(n){
		ret = n&1LL?ret*a%mod:ret;
		n >>= 1;
		a = a*a%mod;
	}
	return ret;
}

ll dp[maxn][3];

void pre(){
	dp[1][1] = 2;
	dp[1][2] = 0;
	for(int i=2;i<maxn;i++){
		dp[i][1] = (dp[i-1][1]+dp[i-1][2])%mod;
		dp[i][2] = dp[i-1][1];
	}
}

int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	ll n,m;
	pre();
	while(cin>>n>>m){
		if(n==1){
			cout<<(dp[m][1]+dp[m][2])%mod<<endl;
			continue;
		}else if(m==1){
			cout<<(dp[n][1]+dp[n][2])%mod<<endl;
			continue;
		}
		ll ans = (dp[n][1]+dp[n][2]);
		ans = ans + dp[m][1] + dp[m][2] - 2LL + mod;
		ans = ans%mod;
		cout<<ans<<endl;
	}
	return 0;
}