#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
const int mod = 1000000007;
int n;
char s[maxn];
vector<int> A;
int dp[maxn];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	dp[0]=dp[1]=1;
	for(int i=1;i<=n;++i)dp[i]=(dp[i-1]+dp[i-2])%mod;
	for(int i=1;i<=n;++i)if(s[i]=='w'||s[i]=='m'){puts("0");return 0;}
	int len=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='u')
		{
			if(s[i-1]=='u')len++;
			else
			{
				if(len)A.push_back(len);
				len=1;
			}
		}
		else if(s[i]=='n') 
		{
			if(s[i-1]=='n')len++;
			else
			{
				if(len)A.push_back(len);
				len=1;
			} 
		}
		else
		{
			if(len)A.push_back(len);
			len=0;
		}
	}
	if(len)A.push_back(len);
	int ans=1;
	for(auto len: A)ans=1ll*ans*dp[len]%mod;
	printf("%d\n",ans);
}