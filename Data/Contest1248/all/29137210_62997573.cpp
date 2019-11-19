#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

ll dp[500001];
ll mod = 1e9+7;
ll f(int i){
	if(i==1){
		return 2;
	}
	if(i==2){
		return 4;
	}
	if(dp[i] != -1){
		return dp[i];
	}
	dp[i] = (f(i-1)%mod + f(i-2)%mod)%mod;
	return dp[i];
}

int main(){
	int n,m;
	cin>>n>>m;	
	memset(dp,-1,sizeof(dp));
	ll ans = f(m) + f(n)-2;

	// cout<<f(m)<<" "<<f(n)<<" "<<ans<<endl;

	ans = (ans+mod)%mod;

	cout<<ans<<endl;
}
