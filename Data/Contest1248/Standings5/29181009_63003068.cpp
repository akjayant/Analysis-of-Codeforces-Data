#include<bits/stdc++.h>
using namespace std;
#define int long long int
int dp[100005];
signed main()
{
	int n,m,k=100005,mod=1e9+7;
	cin>>n>>m;
	dp[0]=dp[1]=1;
	for(int i=0;i<k-2;i++)
	{
		if(!dp[i])
		{
			dp[i] = dp[i-1] + dp[i-2];
			dp[i]%=mod;
		}
	}

	int ans = dp[n]+dp[m];
	ans*=2;
	ans%=mod;
	ans-=2;
	ans+=mod;
	ans%=mod;

	cout<<ans<<endl;
    return 0;
}


