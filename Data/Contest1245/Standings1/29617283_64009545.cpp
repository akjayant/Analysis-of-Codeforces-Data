#include<bits/stdc++.h>
#define ll long long
#define N 1000050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,k,l,r,a,b,c,ans,sum,dp[N];
char s[N];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	if(s[0]=='w'||s[0]=='m')
	{
		cout<<0;
		return 0;
	}
	n=strlen(s);
	dp[0]=dp[1]=1;
	for(int i=1;i<n;i++)
	if(s[i]=='w'||s[i]=='m')
	n=0;
	else
	if(s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n'))
	dp[i+1]=(dp[i-1]+dp[i])%mod;
	else
	dp[i+1]=dp[i];
	if(n)
	cout<<dp[n];
	else
	cout<<0;
	return 0;
}
