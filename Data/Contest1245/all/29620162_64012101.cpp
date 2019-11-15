#include <bits/stdc++.h>
using namespace std;
long long int N=1000000007;

int main() {
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='m' || s[i]=='w'){
			cout<<0;
			return 0;
		}
	}
	long long int dp[100005];
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	for(int i=4; i<100005; i++){
		dp[i]=(dp[i-1]+dp[i-2])%N;
	}
	long long int x=0;
	long long int num=0;
	long long int ans=1;
	// x==1 means u x==2 means n
	for(int i=0; i<s.size(); i++){
		
		if(s[i]!='u' && s[i]!='n'){
			x=0;
			ans=(ans*dp[num])%N;
			num=0;
			continue;
		}
		if(s[i]=='n'){
			if(x==2){
				num++;
				if(i==s.size()-1){
					ans=(ans*dp[num])%N;
				}
				continue;
			}
			if(x==1){
				ans=(ans*dp[num])%N;
				num=1;
				x=2;
				continue;
			}
			if(x==0){
				num=1;
				x=2;
			}
		}
		if(s[i]=='u'){
			if(x==1){
				num++;
				if(i==s.size()-1){
					ans=(ans*dp[num])%N;
				}
				continue;
			}
			if(x==2){
				ans=(ans*dp[num])%N;
				num=1;
				x=1;
				continue;
			}
			if(x==0){
				num=1;
				x=1;
			}
		}
	}
	cout<<ans;
	return 0;
}