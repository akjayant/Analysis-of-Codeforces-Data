#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;

char s[100005];
long long dp[100005][2];

long long calc(int k) {
	return (dp[k][0]+dp[k][1])%mod;
}
int n;
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) {
		if(s[i]=='w' || s[i]=='m') {
			return printf("0\n"),0;
		}
	}
	dp[1][1]=1;
	dp[1][0]=0;
	for(int i=2;i<=n;i++) {
		dp[i][0]=dp[i-1][1]%mod;
		dp[i][1]=(dp[i-1][0]+dp[i-1][1])%mod;
	}
	long long ans=1;
	for(int i=1;i<=n;) {
		if(s[i]=='u' || s[i]== 'n') {
			char c=s[i];
			int cnt=1;
			while(i<n && s[i+1]==c) cnt++,i++;
			if(cnt>=2) ans=ans*calc(cnt)%mod;
		}
		i++;
	}
	printf("%lld\n",ans);
}