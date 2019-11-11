#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;
int dp[100005];

int main(){
	string s; cin >> s;
	if(count(s.begin(),s.end(),'m') || count(s.begin(),s.end(),'w')){
		cout << 0 << endl;
		return 0;
	}
	dp[0]=1;
	dp[1]=1;
	for(int i=1;i<100005;i++){
		dp[i]=(dp[i-2]+dp[i-1])%mod;
	}
	int ans=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='n' || s[i]=='u'){
			int val=0;
			for(int j=i;(j<s.size())&&(s[j]==s[i]);j++){
				val++;
			}
			ans=(1ll*ans*dp[val])%mod;
			i=i+val-1;
		}
	}
	cout << ans << endl;
	return 0;
}