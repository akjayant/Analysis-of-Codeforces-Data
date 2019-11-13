#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
char s[100001];
int dp[100001];
signed main() 
{
	cin>>s+1;
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='w'||s[i]=='m')
		{
			printf("0");
			return 0;
		}
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]+=dp[i-1];
		if(s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n'))
			dp[i]+=dp[i-2],dp[i]%=mod;
	}
	printf("%d",dp[n]);
	return 0;
}
