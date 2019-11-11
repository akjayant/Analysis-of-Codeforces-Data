#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
long long dp[int(1e5+1)];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,i;
	string s;
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++)
		if(s[i]=='m' || s[i]=='w')
		{
			cout<<"0\n";
			return 0;
		}
	dp[0]=1;
	dp[1]=1;
	if(s[0]==s[1] && (s[0]=='u' || s[0]=='n'))dp[1]++;
	for(i=2;i<n;i++)
	{
		dp[i]=dp[i-1];
		if(s[i]==s[i-1] && (s[i]=='n' || s[i]=='u'))dp[i]=(dp[i]+dp[i-2])%MOD;
	}
	cout<<dp[n-1]<<'\n';
}
