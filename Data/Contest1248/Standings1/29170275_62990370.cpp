#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,m;
ll dp[100001];
int MA = 1000000007;
ll en(int a){
	ll x = 2;
	ll re=1;
	while(1){
		if(a&1)re*=x;
		re%=MA;
		x*=x;
		x%=MA;
		a>>=1;
		if(a==0)break;
	}
	return re;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	dp[1]=2;
	dp[2]=4;
	dp[3]=6;
	for(int i=4 ; i<=max(n,m) ; i++){
		dp[i] = dp[i-1]+dp[i-2];
		dp[i]%=MA;
	}
	if(n==1){
		cout<<dp[m];
		return 0;
	}
	else if(m==1){
		cout<<dp[n];
		return 0;
	}
	ll ans = ((dp[n]-2)+dp[m])%MA;
	cout<<ans;
}