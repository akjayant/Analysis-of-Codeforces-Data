#include<algorithm>
#include<iostream>
#include<complex>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<ctime>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define N 100039
#define mod 1000000007
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int len,dp[N],ans=1;
char ch[N];
int main()
{
	scanf(" %s",ch);
	len=strlen(ch);
	dp[0]=dp[1]=1;
	for(int a=2;a<=len;a++)
	{
		dp[a]=dp[a-1]+dp[a-2];
		dp[a]%=mod;
	}
	if(ch[0]=='m' || ch[0]=='w') ans=0;
	for(int a=1,b=(ch[0]=='u' || ch[0]=='n');a<=len && ans;a++)
	{
		if(ch[a]=='m' || ch[a]=='w') ans=0;
		if(ch[a-1]!=ch[a])
		{
			ans=(ll)ans*dp[b]%mod;
			b=0;
		}
		if(ch[a]=='u' || ch[a]=='n') b++;
	}
	printf("%d",ans);
	return 0;
}
/*Kamii_Sinogi*/