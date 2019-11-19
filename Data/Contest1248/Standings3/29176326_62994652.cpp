#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define ll long long int
#define mp make_pair
#define sz(arr) (ll)arr.size()
#define MOD 1000000007

using namespace std;

ll power(ll a,ll b){
	if (b==0) return 1;
	else if (b%2==0) return power((a*a)%MOD,b/2);
	else return (a*power((a*a)%MOD,b/2))%MOD;
}

int main(){
	ll n,m;
	cin>>n>>m;
	vector<ll> dp(max(n+1,m+1));
	dp[1]=1;
	dp[2]=2;
	for(int i=3; i<=max(n+1,m+1); i++){
		dp[i]=(dp[i-1]+dp[i-2])%MOD;
	}
	ll ans=2*((dp[m]-1)%MOD);
	ans%=MOD;
	ans+=2*dp[n];
	ans%=MOD;
	cout<<ans;
}
