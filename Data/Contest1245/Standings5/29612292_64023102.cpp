#include<bits/stdc++.h>
using namespace std;const int N=1e5+7,mod=1e9+7;
int dp[N][2],n,i,j,ans;char s[N];
int main(){
	for(dp[1][0]=ans=1,i=2;i<N;++i){
		dp[i][1]=dp[i-1][0];
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
	}
	for(scanf("%s",s+1),n=strlen(s+1),i=1;i<=n;)if(s[i]=='n'||s[i]=='u'){
		for(j=i;j<=n&&s[j]==s[i];++j);
		ans=1LL*ans*(dp[j-i][0]+dp[j-i][1])%mod;i=j;
	}else if(s[i]=='m'||s[i]=='w')ans=0,++i;
	else ++i;
	printf("%d\n",ans);
}