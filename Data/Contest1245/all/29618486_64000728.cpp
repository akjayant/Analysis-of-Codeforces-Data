#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+10,mod=1e9+7;
int dp[N];
int main(){
	dp[0]=1,dp[1]=1;
	for(int i=2;i<N;++i){
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=mod;
	}
	string s;
	cin>>s;int f=1;
	ll ans=1;
	for(int i=0;i<s.size()&&f;++i)
	{
		if(s[i]=='w'||s[i]=='m') f=0;
		if(s[i]=='n')
		{
			int j=i;
			int pre=0;
			while(j<s.size()&&s[j]=='n')pre++,++j;
			ans=(ans*dp[pre])%mod;
			i=j-1;
		}
		if(s[i]=='u')
		{
			int j=i;
			int pre=0;
			while(j<s.size()&&s[j]=='u')pre++,++j;
			ans=(ans*dp[pre])%mod;
			i=j-1;
		}
	}
	//printf("d:%d\n",f)
	if(f==0) {
		printf("0");
		return 0;
	}
	printf("%lld\n",ans);
}