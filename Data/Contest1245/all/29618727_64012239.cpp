#include<bits/stdc++.h>
typedef long long ll;
ll mod =1000000007;
using namespace std;
int n;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

string s;
ll dp[100005][2][2];

ll func(int index,int uu,int nn)
{
	if(index==n)
		return 1;
	if(dp[index][nn][uu]!=-1)
		return dp[index][nn][uu];
	if(s[index]=='m' || s[index]=='w')
		return 0;
	if(s[index]=='u')
	{
		if(uu==1)
			return dp[index][nn][uu]=(func(index+1,1,0)+func(index+1,0,0))%mod;

		return dp[index][nn][uu]=func(index+1,1,0);
	}
	else
	if(s[index]=='n')
	{
		if(nn==1)
			return dp[index][nn][uu]=(func(index+1,0,1)+func(index+1,0,0))%mod;

		return dp[index][nn][uu]=func(index+1,0,1);

	}
	else
		return dp[index][nn][uu]=func(index+1,0,0);
}
int main()
{
	int i,j,fl,test;
	cin>>s;
	n=s.length();
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",func(0,0,0) );
	return 0;
}