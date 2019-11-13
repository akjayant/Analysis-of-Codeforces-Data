#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 1e9+7;

int dp[100004];

#undef int
int main()
{
#define int long long int
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3;i<=100000;i++)
		dp[i] = (dp[i-1] + dp[i-2]) % mod;
	string s;
	cin>>s;
	int cnt = 0;
	int ans = 1;
	s+='#';
	int n = s.size();
	for(int i = 0;i<n;i++)
	{
		if(s[i] == 'm' || s[i] == 'w')
		{
			cout<<0<<endl;
			return 0;
		}
	}
	for(int i = 0;i<n;i++)
	{
		if(s[i]=='n')
			cnt++;
		else if(cnt)
		{	
			ans = (ans * dp[cnt]) % mod;
			cnt = 0;
		}	
	}
	for(int i = 0;i<n;i++)
	{
		if(s[i]=='u')
			cnt++;
		else if(cnt)
		{	
			ans = (ans * dp[cnt]) % mod;
			cnt = 0;
		}	
	}
	cout<<ans<<endl;

	return 0;
}