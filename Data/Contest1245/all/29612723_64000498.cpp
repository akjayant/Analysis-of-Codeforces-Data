#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll dp[100001];
int main(){
	ios::sync_with_stdio(false);
	string s;cin >> s;
	for(auto cur:s){
		if(cur=='m' || cur=='w') return cout << "0\n",0;
	}
	dp[0]=dp[1]=1;
	for(int i=2; i<=s.size() ;i++){
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	}
	char prv='0';int cnt=0;
	ll ans=1;
	for(auto cur:s){
		if(cur!=prv){
			if(prv!='u' && prv!='n');
			else{
				ans=ans*dp[cnt]%mod;
			}
			prv=cur;cnt=0;
		}
		cnt++;
	}
	if(true){
		if(prv!='u' && prv!='n');
		else{
			ans=ans*dp[cnt]%mod;
		}
		//prv=cur;cnt=0;
	}
	cout << ans << '\n';
}