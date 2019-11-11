#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define pii pair<ll,ll>
#define mod 1000000007
int main(){
	io;
	string s;cin>>s;
	int u=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='m' || s[i]=='w'){
			cout<<0<<endl;
			return 0;
		}
	}
	vector<ll>dp(s.length()+1);
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=s.length();i++){
		if(s[i-1]!=s[i-2]){
			dp[i]=dp[i-1];
		}
		else{
			if(s[i-1]=='u' || s[i-1]=='n'){
				dp[i]=(dp[i-1]+dp[i-2])%mod;
			}
			else{
				dp[i]=dp[i-1];
			}
		}
	}
	cout<<dp[s.length()];
	return 0;
}



















